%code requires{
  // A lot of this parser is based off the ANSI C Yacc grammar
  // https://www.lysator.liu.se/c/ANSI-C-grammar-y.html
  #include "ast.hpp"
  #include <string>

  extern void update_type_map(std::string identifier, std::string type);
  extern const Node *g_root; //A way of getting the AST out
  extern FILE *yyin;

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
	ListPtr branch;
  	const Node *node;
  	double number;
  	std::string *string;
}


%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CHAR_LITERAL
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <string> IDENTIFIER STRING_LITERAL CHAR_LITERAL
%type <number> CONSTANT

%type <branch> BODY PARAMETER ARGUMENTS HEADS SWITCH_BODY ENUM_BODY STRUCT_UNION_BODY
%type <node> DATA_TYPES STATEMENT BLOCK EXPR TERM UNARY FACTOR STRUCT_UNION_INSIDE
%type <node> LINE DECLARATION IF_ELSE_SWITCH LOOP OUTPUT CASES ENUMS ENUM_DEC POINTER_INIT POINTER_CALL ADDRESS_OF
%type <node> HEAD STRUCT_UNION OPERATORS ARRAY FUNCTION_DEF INTERIOR_EXPR EQUALS

//CHECK: uncommenting the 2 lines below fails custom/char.c due to + - issue */
// %nonassoc '+' '-'
// %nonassoc '*' '/'

%left '*' '/' '%'
%left '+' '-'
%right '='



%start ROOT

%%
/* Extracts AST */
ROOT
	: OUTPUT { g_root =  $1;};

//OUTPUT NODE
OUTPUT
	: HEADS {$$ = new Output($1);}

//LIST OF FUNCTION HEADS
HEADS
	: HEADS HEAD		{$$ = concat_list($2,$1);}
	| HEAD				{$$ = init_list($1);}

//HEAD OF FUNCTIONS
HEAD
	: FUNCTION_DEF										{$$ = $1;}
	| DECLARATION ';'									{$$ = $1;}
	| ENUMS ';'											{$$ = $1;}
	| STRUCT_UNION ';'									{$$ = $1;}
	| THROWAWAY	';'										{$$ = new Throwaway();}

FUNCTION_DEF
	: DATA_TYPES IDENTIFIER '(' ')' ';'						{$$ = new FunctionDef($1,$2,NULL,NULL);}
	| DATA_TYPES IDENTIFIER '(' PARAMETER ')' ';'			{$$ = new FunctionDef($1,$2,$4,NULL);}
	| DATA_TYPES IDENTIFIER '(' ')' BLOCK					{$$ = new FunctionDef($1,$2,NULL,$5);}
	| DATA_TYPES IDENTIFIER '(' PARAMETER ')' BLOCK			{$$ = new FunctionDef($1,$2,$4,$6);}
	| DATA_TYPES '*' IDENTIFIER '(' ')' ';'					{$$ = new FunctionDef($1,$3,NULL,NULL);}
	| DATA_TYPES '*' IDENTIFIER '(' PARAMETER ')' ';'		{$$ = new FunctionDef($1,$3,$5,NULL);}
	| DATA_TYPES '*' IDENTIFIER '(' ')' BLOCK				{$$ = new FunctionDef($1,$3,NULL,$6);}
	| DATA_TYPES '*' IDENTIFIER '(' PARAMETER ')' BLOCK		{$$ = new FunctionDef($1,$3,$5,$7);}
	| CHAR '*' IDENTIFIER '(' ')' ';'						{$$ = new FunctionDef((new Type(_Types::_char)),$3,NULL,NULL);}
	| CHAR '*' IDENTIFIER '(' PARAMETER ')' ';'				{$$ = new FunctionDef((new Type(_Types::_char)),$3,$5,NULL);}
	| CHAR '*' IDENTIFIER '(' ')' BLOCK						{$$ = new FunctionDef((new Type(_Types::_char)),$3,NULL,$6);}
	| CHAR '*' IDENTIFIER '(' PARAMETER ')' BLOCK			{$$ = new FunctionDef((new Type(_Types::_char)),$3,$5,$7);}


PARAMETER
	: PARAMETER ',' DECLARATION		{$$ = concat_list($3,$1);}
	| DECLARATION					{$$ = init_list($1);}


BLOCK
	: '{' BODY '}'			{$$ = new Block($2);}
	| '{' '}'				{$$ = NULL;}

BODY
	: LINE BODY				{$$ = concat_list($1,$2);}
	| LINE					{$$ = init_list($1);}

LINE
	: STATEMENT	';'			{$$ = $1;}
	| DECLARATION ';'		{$$ = $1;}
	| BLOCK					{$$ = $1;}
	| IF_ELSE_SWITCH		{$$ = $1;}
	| LOOP					{$$ = $1;}


STATEMENT
	: RETURN EXPR			{ $$ = new Return($2);}
	| RETURN				{ $$ = new Return(NULL);}
	| CONTINUE 	 			{ $$ = new Continue();}
	| BREAK 	 			{ $$ = new Break();}
	| THROWAWAY				{ $$ = new Throwaway();}

DECLARATION
	: IDENTIFIER '=' EXPR								{$$ = new Declaration(NULL,(new Variable(*$1)),$3);} //temporary need to change
	| POINTER_INIT '=' EXPR								{$$ = new Declaration(NULL,$1,$3);}
	| DATA_TYPES IDENTIFIER								{$$ = new Declaration($1,(new Variable(*$2)),NULL);} //need to handle empty initialisations
	| DATA_TYPES POINTER_INIT							{$$ = new Declaration($1,$2,NULL);} //need to handle empty initialisations
	| DATA_TYPES IDENTIFIER '=' EXPR					{$$ = new Declaration($1,(new Variable(*$2)),$4);} //temporary need to change
	| DATA_TYPES POINTER_INIT '=' EXPR					{$$ = new Declaration($1,$2,$4);}
	| DATA_TYPES IDENTIFIER '[' EXPR ']'				{$$ = new Array_Declaration($1, (new Variable(*$2)), $4);}
	| CHAR '*' IDENTIFIER								{$$ = new Declaration((new Type(_Types::_char)), (new Pointer_Init(new Variable(*$3))), NULL) ;}
	| CHAR '*' IDENTIFIER '=' STRING_LITERAL 			{$$ = new Strings((new Type(_Types::_char)),  (new Variable(*$3)), *$5);}
	| STRUCT IDENTIFIER IDENTIFIER						{$$ = new Struct_Init((new Variable(*$2)),(new Variable(*$3)));}
	| IDENTIFIER '.' IDENTIFIER '=' EXPR				{$$ = new Declaration(NULL,new Variable( (*$1 + std::string(".",1) + *$3) ),$5);}
	| EXPR 		//for assignment operators

EXPR
	: INTERIOR_EXPR 						{ $$ = $1;}
	| EXPR RIGHT_ASSIGN EXPR 				{ $$ = new RightAssignOperator($1, $3); }
	| EXPR LEFT_ASSIGN EXPR 				{ $$ = new LeftAssignOperator($1, $3); }
	| EXPR ADD_ASSIGN EXPR 					{ $$ = new AddAssignOperator($1, $3); }
	| EXPR SUB_ASSIGN EXPR 					{ $$ = new SubAssignOperator($1, $3); }
	| EXPR MUL_ASSIGN EXPR 					{ $$ = new MulAssignOperator($1, $3); }
	| EXPR DIV_ASSIGN EXPR 					{ $$ = new DivAssignOperator($1, $3); }
	| EXPR MOD_ASSIGN EXPR 					{ $$ = new ModAssignOperator($1, $3); }
	| EXPR AND_ASSIGN EXPR 					{ $$ = new AndAssignOperator($1, $3); }
	| EXPR XOR_ASSIGN EXPR 					{ $$ = new XorAssignOperator($1, $3); }
	| EXPR OR_ASSIGN EXPR 					{ $$ = new OrAssignOperator($1, $3); }

//EXPRESSIONS
INTERIOR_EXPR
	: EQUALS												{ $$ = $1; }
	| INTERIOR_EXPR '>' INTERIOR_EXPR						{ $$ = new GthanOperator($1, $3); }
	| INTERIOR_EXPR '<' INTERIOR_EXPR						{ $$ = new LthanOperator($1, $3); }
	| INTERIOR_EXPR GE_OP INTERIOR_EXPR						{ $$ = new GthanEqOperator($1, $3); }
	| INTERIOR_EXPR LE_OP INTERIOR_EXPR						{ $$ = new LthanEqOperator($1, $3); }
	| INTERIOR_EXPR OR_OP INTERIOR_EXPR						{ $$ = new OrOperator($1, $3); }
	| INTERIOR_EXPR AND_OP INTERIOR_EXPR  					{ $$ = new AndOperator($1, $3); }
	| INTERIOR_EXPR '&' INTERIOR_EXPR 						{ $$ = new AndBitwiseOperator($1, $3); }
	| INTERIOR_EXPR '|' INTERIOR_EXPR 						{ $$ = new OrBitwiseOperator($1, $3); }
	| INTERIOR_EXPR '^' INTERIOR_EXPR 						{ $$ = new XorBitwiseOperator($1, $3); }

EQUALS
	: OPERATORS									{ $$ = $1; }
	| EQUALS EQ_OP EQUALS						{ $$ = new EqOperator($1, $3); }
	| EQUALS NE_OP EQUALS						{ $$ = new NEqOperator($1, $3); }

OPERATORS
	: TERM 									{$$ = $1; }
	| OPERATORS '+' OPERATORS 				{$$ = new AddOperator($1, $3); }
    | OPERATORS '-' OPERATORS 				{$$ = new SubOperator($1, $3); }
	| OPERATORS RIGHT_OP OPERATORS 			{ $$ = new RightShiftOperator($1, $3); }
	| OPERATORS LEFT_OP OPERATORS 			{ $$ = new LeftShiftOperator($1, $3); }



TERM
	: UNARY             			{ $$ = $1; }
    | TERM '*' TERM     			{ $$ = new MulOperator($1, $3);}
    | TERM '/' TERM   				{ $$ = new DivOperator($1, $3);}
	| TERM '%' TERM 				{ $$ = new ModOperator($1, $3);}


UNARY
	: FACTOR	  								{ $$ = $1; }
	| '-' FACTOR  								{ $$ = new NegOperator($2); }
	| '+' FACTOR								{ $$ = $2; }
	| FACTOR INC_OP	 							{ $$ = new IncOperator_Post($1); }
	| INC_OP FACTOR 	 						{ $$ = new IncOperator_Pre($2); }
	| FACTOR DEC_OP								{ $$ = new DecOperator_Post($1); }
	| DEC_OP FACTOR 							{ $$ = new DecOperator_Pre($2); }
	| '~' FACTOR 								{ $$ = new NotBitwiseOperator($2); }
	| '!' FACTOR								{ $$ = new NotOperator($2); }


FACTOR
	: CONSTANT     					{$$ = new Number( $1 );}
	| CHAR_LITERAL					{$$ = new Chars(*$1);}
	| STRING_LITERAL 				{$$ = new Strings_Output(*$1);}
    | '(' EXPR ')' 					{$$ = $2;}
    | IDENTIFIER 					{$$ = new Variable( *$1 );}
	| IDENTIFIER '(' ')'			{$$ = new FunctionCall($1,NULL);}
	| IDENTIFIER '(' ARGUMENTS ')'	{$$ = new FunctionCall($1,$3);}
	| SIZEOF '(' EXPR ')'			{$$ = new SizeOf($3);}
	| SIZEOF '(' DATA_TYPES ')'		{$$ = new SizeOf($3);}
	| POINTER_CALL					{$$ = $1;}
	| ADDRESS_OF					{$$ = $1;}
	| ARRAY 						{$$ = $1;}
	| IDENTIFIER '.' IDENTIFIER		{$$ = new Variable( (*$1 + std::string(".",1) + *$3) );}


ARRAY
	: IDENTIFIER '[' EXPR ']'    		 	{ $$ = new Array_Index((new Variable(*$1)), $3, NULL); }
	| IDENTIFIER '[' EXPR ']' '=' EXPR 	 	{ $$ = new Array_Index((new Variable(*$1)), $3, $6); }
	/* | IDENTIFIER '[' ']' '=' '{' VALUES '}'

VALUES
	: VALUE
	| VALUE ',' VALUES */

ARGUMENTS
	: ARGUMENTS ',' EXPR			{$$ = concat_list($3,$1);}
	| EXPR							{$$ = init_list($1);}







//IF ELSE SWITCH BLOCKS

IF_ELSE_SWITCH
	: IF '(' EXPR ')' BLOCK							{$$ = new ifelse($3,$5,NULL);}
	| IF '(' EXPR ')' BLOCK ELSE BLOCK				{$$ = new ifelse($3,$5,$7);}
	| EXPR '?' BLOCK ':' BLOCK						{$$ = new ifelse($1, $3, $5);}
	| SWITCH '(' EXPR ')' '{' SWITCH_BODY '}' 		{$$ = new switch_statement($3, $6);}

CASES
	: CASE EXPR ':' BODY 							{ $$ = new case_statement($2, new Block($4)); }
	| DEFAULT ':' BODY 								{ $$ = new default_statement( new Block($3)); }

SWITCH_BODY
	: CASES	SWITCH_BODY			    				{$$ = concat_list($1,$2);}
	| CASES											{$$ = init_list($1);}





//ENUM

ENUM_DEC
	: IDENTIFIER									{$$ = new Enum_Dec((new Variable(*$1)),NULL);}
	| IDENTIFIER '=' FACTOR							{$$ = new Enum_Dec((new Variable(*$1)),$3);}	//Our AST does not yet accept expressions in enums

ENUM_BODY
	: ENUM_DEC										{$$ = init_list($1);}
	| ENUM_DEC ',' ENUM_BODY						{$$ = concat_list($1,$3);}

ENUMS
	: ENUM IDENTIFIER '{' ENUM_BODY	'}'				{$$ = new Enum($4);}





//STRUCT

STRUCT_UNION
	: STRUCT IDENTIFIER '{' STRUCT_UNION_BODY '}' 		{$$ = new Struct_Dec((new Variable(*$2)),$4);}

STRUCT_UNION_BODY
	: STRUCT_UNION_INSIDE ';'							{$$ = init_list($1);}
	| STRUCT_UNION_INSIDE ';' STRUCT_UNION_BODY			{$$ = concat_list($1,$3);}

STRUCT_UNION_INSIDE
	: DATA_TYPES IDENTIFIER								{$$ = new Declaration($1,(new Variable(*$2)),NULL);}





//POINTERS

POINTER_INIT
	: '*' IDENTIFIER					{$$ =  new Pointer_Init(new Variable(*$2));}
	//nested dereferencing to be implemented
POINTER_CALL
	: '*' IDENTIFIER					{$$ =  new Pointer_Call(new Variable(*$2));}
	//nested dereferencing to be implemented

ADDRESS_OF
	: '&' IDENTIFIER					{$$ = new Address(new Variable(*$2));}



//LOOPS

LOOP
	: FOR '(' DECLARATION ';' EXPR ';' DECLARATION ')' BLOCK	{$$ = new forloop($3,$5,$7,$9);}
	| FOR '('  ';' EXPR ';' DECLARATION ')' BLOCK				{$$ = new forloop(NULL,$4,$6,$8);}
	| FOR '(' DECLARATION ';'  ';' DECLARATION ')' BLOCK		{$$ = new forloop($3,NULL,$6,$8);}
	| FOR '(' DECLARATION ';' EXPR ';'  ')' BLOCK				{$$ = new forloop($3,$5,NULL,$8);}
	| FOR '('  ';'  ';' DECLARATION ')' BLOCK					{$$ = new forloop(NULL,NULL,$5,$7);}
	| FOR '(' DECLARATION ';'  ';'  ')' BLOCK					{$$ = new forloop($3,NULL,NULL,$7);}
	| FOR '('  ';' EXPR ';'  ')' BLOCK							{$$ = new forloop(NULL,$4,NULL,$7);}
	| FOR '('  ';'  ';'  ')' BLOCK								{$$ = new forloop(NULL,NULL,NULL,$6);}
	/*
	| FOR '(' DECLARATION ';' EXPR ';' DECLARATION ')' LINE		{$$ = new forloop($3,$5,$7,new Block(init_list($9)));}
	| FOR '('  ';' EXPR ';' DECLARATION ')' LINE 				{$$ = new forloop(NULL,$4,$6,new Block(init_list($8)));}
	| FOR '(' DECLARATION ';'  ';' DECLARATION ')' LINE 		{$$ = new forloop($3,NULL,$6,new Block(init_list($8)));}
	| FOR '(' DECLARATION ';' EXPR ';'  ')' LINE 				{$$ = new forloop($3,$5,NULL,new Block(init_list($8)));}
	| FOR '('  ';'  ';' DECLARATION ')' LINE 					{$$ = new forloop(NULL,NULL,$5,new Block(init_list($7)));}
	| FOR '(' DECLARATION ';'  ';'  ')' LINE 					{$$ = new forloop($3,NULL,NULL,new Block(init_list($7)));}
	| FOR '('  ';' EXPR ';'  ')' LINE 							{$$ = new forloop(NULL,$4,NULL,new Block(init_list($7)));}
	| FOR '('  ';'  ';'  ')' LINE								{$$ = new forloop(NULL,NULL,NULL,new Block(init_list($6)));}
	*/
	//Could have done all the above as a sub token if had more time

	| WHILE '(' EXPR ')' BLOCK									{$$ = new whileloop($3,$5);}
	//| WHILE '(' EXPR ')' LINE									{$$ = new whileloop($3,new Block(init_list($5)));}

	| DO BLOCK WHILE '(' EXPR ')' ';'							{$$ = new doloop($2,$5);}
	| DO LINE WHILE '(' EXPR ')' ';'							{$$ = new doloop(new Block(init_list($2)),$5);}
	| DO ';' WHILE '(' EXPR ')' ';'								{$$ = new doloop(NULL,$5);}





//DATA TYPES

DATA_TYPES
	: INT				{$$ = new Type(_Types::_int);}
	| SIGNED INT		{$$ = new Type(_Types::_int);}
	| UNSIGNED INT		{$$ = new Type(_Types::_unsigned_int);}
	| INT SIGNED		{$$ = new Type(_Types::_int);}
	| INT UNSIGNED		{$$ = new Type(_Types::_unsigned_int);}


	| LONG				{$$ = new Type(_Types::_long);}
	| SIGNED LONG		{$$ = new Type(_Types::_long);}
	| UNSIGNED LONG		{$$ = new Type(_Types::_unsigned_long);}
	| LONG SIGNED		{$$ = new Type(_Types::_long);}
	| LONG UNSIGNED		{$$ = new Type(_Types::_unsigned_long);}

	| CHAR				{$$ = new Type(_Types::_char);}
	| SIGNED CHAR		{$$ = new Type(_Types::_signed_char);}
	| UNSIGNED CHAR		{$$ = new Type(_Types::_unsigned_char);}
	| CHAR SIGNED		{$$ = new Type(_Types::_signed_char);}
	| CHAR UNSIGNED		{$$ = new Type(_Types::_unsigned_char);}

	| SHORT				{$$ = new Type(_Types::_short);}
	| SIGNED SHORT		{$$ = new Type(_Types::_short);}
	| UNSIGNED SHORT	{$$ = new Type(_Types::_unsigned_short);}
	| SHORT SIGNED		{$$ = new Type(_Types::_short);}
	| SHORT UNSIGNED	{$$ = new Type(_Types::_unsigned_short);}

	| SIGNED			{$$ = new Type(_Types::_int);}
	| UNSIGNED			{$$ = new Type(_Types::_unsigned_int);}

	| FLOAT				{$$ = new Type(_Types::_float);}
	| DOUBLE			{$$ = new Type(_Types::_double);}

	| LONG DOUBLE 		{$$ = new Type(_Types::_long_double);}
	| DOUBLE LONG 		{$$ = new Type(_Types::_long_double);}

	| VOID 				{$$ = new Type(_Types::_void);}

THROWAWAY
	: TYPEDEF DATA_TYPES IDENTIFIER						{update_type_map(*$3, $2->getType());}
	| TYPEDEF DATA_TYPES '*' IDENTIFIER					{update_type_map(*$4, $2->getType());}

%%


const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST(std::string filename){
  yyin = fopen(filename.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  g_root = NULL;
  yyparse();
  return g_root;
}
