%code requires{
  // A lot of this parser is based off the ANSI C Yacc grammar
  // https://www.lysator.liu.se/c/ANSI-C-grammar-y.html
  #include "ast.hpp"
  #include <string>

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


%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <string> IDENTIFIER STRING_LITERAL
%type <number> CONSTANT

%type <branch> BODY PARAMETER ARGUMENTS HEADS SWITCH_BODY
%type <node> DATA_TYPES STATEMENT BLOCK EXPR TERM UNARY FACTOR SWITCH_BLOCK
%type <node> LINE DECLARATION IF_ELSE_SWITCH LOOP OUTPUT CASES
%type <node> HEAD

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
	: DATA_TYPES IDENTIFIER '(' ')' ';'					{$$ = new FunctionDef($1,$2,NULL,NULL);}
	| DATA_TYPES IDENTIFIER '(' PARAMETER ')' ';'		{$$ = new FunctionDef($1,$2,$4,NULL);}
	| DATA_TYPES IDENTIFIER '(' ')' BLOCK				{$$ = new FunctionDef($1,$2,NULL,$5);}
	| DATA_TYPES IDENTIFIER '(' PARAMETER ')' BLOCK		{$$ = new FunctionDef($1,$2,$4,$6);}
	| DECLARATION ';'									{$$ = $1;}


PARAMETER
	: PARAMETER ',' DECLARATION		{$$ = concat_list($3,$1);}
	| DECLARATION					{$$ = init_list($1);}


BLOCK
	: '{' BODY '}'			{$$ = new Block($2);}
	| '{' '}'				{$$ = NULL;}

BODY
	: LINE BODY		{$$ = concat_list($1,$2);}
	| LINE			{$$ = init_list($1);}

LINE
	: STATEMENT	';'		{$$ = $1;}
	| DECLARATION ';'	{$$ = $1;}
	| IF_ELSE_SWITCH	{$$ = $1;}
	| LOOP				{$$ = $1;}


STATEMENT
	: RETURN EXPR			{ $$ = new Return($2);}
	| RETURN				{ $$ = new Return(NULL);}
	| CONTINUE 	 			{ $$ = new Continue();}
	| BREAK 	 			{ $$ = new Break();}

DECLARATION
	: IDENTIFIER '=' EXPR					{$$ = new Declaration(NULL,(new Variable(*$1)),$3);} //temporary need to change
	| DATA_TYPES IDENTIFIER					{$$ = new Declaration($1,(new Variable(*$2)),NULL);} //need to handle empty initialisations
	| DATA_TYPES IDENTIFIER '=' EXPR		{$$ = new Declaration($1,(new Variable(*$2)),$4);} //temporary need to change
	| DATA_TYPES IDENTIFIER '[' EXPR ']'	{$$ = new Array_Declaration($1, (new Variable(*$2)), $4);}
	| EXPR 		//for assignment operators





//EXPRESSIONS

EXPR
	: TERM              		{ $$ = $1; }
	//| STRING_LITERAL			// ask UTAs
    | EXPR '+' EXPR 			{ $$ = new AddOperator($1, $3); }
    | EXPR '-' EXPR 			{ $$ = new SubOperator($1, $3); }
	| EXPR '>' EXPR				{ $$ = new GthanOperator($1, $3); }
	| EXPR '<' EXPR				{ $$ = new LthanOperator($1, $3); }
	| EXPR NE_OP EXPR			{ $$ = new NEqOperator($1, $3); }
	| EXPR EQ_OP EXPR			{ $$ = new EqOperator($1, $3); }
	| EXPR GE_OP EXPR			{ $$ = new GthanEqOperator($1, $3); }
	| EXPR LE_OP EXPR			{ $$ = new LthanEqOperator($1, $3); }
	| EXPR OR_OP EXPR			{ $$ = new OrOperator($1, $3); }
	| EXPR AND_OP EXPR  		{ $$ = new AndOperator($1, $3); }
	| '!' EXPR					{ $$ = new NotOperator($2); }
	| EXPR RIGHT_ASSIGN EXPR 	{ $$ = new RightAssignOperator($1, $3); }
	| EXPR LEFT_ASSIGN EXPR 	{ $$ = new LeftAssignOperator($1, $3); }
	| EXPR ADD_ASSIGN EXPR 		{ $$ = new AddAssignOperator($1, $3); }
	| EXPR SUB_ASSIGN EXPR 		{ $$ = new SubAssignOperator($1, $3); }
	| EXPR MUL_ASSIGN EXPR 		{ $$ = new MulAssignOperator($1, $3); }
	| EXPR DIV_ASSIGN EXPR 		{ $$ = new DivAssignOperator($1, $3); }
	| EXPR MOD_ASSIGN EXPR 		{ $$ = new ModAssignOperator($1, $3); }
	| EXPR AND_ASSIGN EXPR 		{ $$ = new AndAssignOperator($1, $3); }
	| EXPR XOR_ASSIGN EXPR 		{ $$ = new XorAssignOperator($1, $3); }
	| EXPR OR_ASSIGN EXPR 		{ $$ = new OrAssignOperator($1, $3); }
	| EXPR '&' EXPR 			{ $$ = new AndBitwiseOperator($1, $3); }
	| EXPR '|' EXPR 			{ $$ = new OrBitwiseOperator($1, $3); }
	| EXPR '^' EXPR 			{ $$ = new XorBitwiseOperator($1, $3); }
	//| '~' EXPR 				// need to do
	| EXPR RIGHT_OP EXPR 		{ $$ = new RightShiftOperator($1, $3); }
	| EXPR LEFT_OP EXPR 		{ $$ = new LeftShiftOperator($1, $3); }
	| EXPR INC_OP	 			{ $$ = new IncOperator_Post($1); }
	| INC_OP EXPR 	 			{ $$ = new IncOperator_Pre($2); }
	| EXPR DEC_OP				{ $$ = new DecOperator_Post($1); }
	| DEC_OP EXPR 				{ $$ = new DecOperator_Pre($2); }
	| IDENTIFIER '[' EXPR ']'    		{ $$ = new Array_Index((new Variable(*$1)), $3, NULL); }
	| IDENTIFIER '[' EXPR ']' '=' EXPR 	{ $$ = new Array_Index((new Variable(*$1)), $3, $6); }


TERM
	: UNARY             { $$ = $1; }
    | TERM '*' TERM     { $$ = new MulOperator($1, $3); }
    | TERM '/' TERM   	{ $$ = new DivOperator($1, $3); }


UNARY
	: FACTOR	  		{ $$ = $1; }
	| '-' FACTOR  		{ $$ = new NegOperator($2); }


FACTOR
	: CONSTANT     					{$$ = new Number( $1 );}
    | '(' EXPR ')' 					{$$ = $2;}
    | IDENTIFIER 					{$$ = new Variable( *$1 );}
	| IDENTIFIER '(' ')'			{$$ = new FunctionCall($1,NULL);}
	| IDENTIFIER '(' ARGUMENTS ')'	{$$ = new FunctionCall($1,$3);}

ARGUMENTS
	: ARGUMENTS ',' EXPR			{$$ = concat_list($3,$1);}
	| EXPR							{$$ = init_list($1);}





//IF ELSE SWITCH BLOCKS

IF_ELSE_SWITCH
	: IF '(' EXPR ')' BLOCK				{$$ = new ifelse($3,$5,NULL);}
	| IF '(' EXPR ')' BLOCK ELSE BLOCK	{$$ = new ifelse($3,$5,$7);}
	| EXPR '?' BLOCK ':' BLOCK			{$$ = new ifelse($1, $3, $5);}
	| SWITCH '(' EXPR ')' SWITCH_BLOCK 		{$$ = new switch_statement($3, $5); }

CASES
	: CASE EXPR ':' BODY 			{ $$ = new case_statement($2, $4); }
	| DEFAULT ':' BODY 				{ $$ = new default_statement($3); }

SWITCH_BLOCK
    : '{' SWITCH_BODY '}'           {$$ = new Block($2);}


SWITCH_BODY
	: CASES	SWITCH_BODY			    {$$ = concat_list($1,$2);}
	| CASES							{$$ = init_list($1);}



//LOOPS

LOOP
	: FOR '(' DECLARATION ';' EXPR ';' DECLARATION ')' BLOCK	{$$ = new forloop($3,$5,$7,$9);}
	| WHILE '(' EXPR ')' BLOCK									{$$ = new whileloop($3,$5);}
	| DO BLOCK WHILE '(' EXPR ')' ';'






//DATA TYPES

DATA_TYPES
	: INT		{$$ = new Type(_Types::_int);}
	| LONG		{$$ = new Type(_Types::_long);}
	| CHAR		{$$ = new Type(_Types::_char);}
	| SHORT		{$$ = new Type(_Types::_short);}
	| SIGNED	{$$ = new Type(_Types::_signed);}
	| UNSIGNED	{$$ = new Type(_Types::_unsigned);}
	| FLOAT		{$$ = new Type(_Types::_float);}
	| DOUBLE	{$$ = new Type(_Types::_double);}
	| VOID 		{$$ = new Type(_Types::_void);}


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

