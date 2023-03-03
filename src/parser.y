%code requires{
  // A lot of this parser is based off the ANSI C Yacc grammar
  // https://www.lysator.liu.se/c/ANSI-C-grammar-y.html
  #include "ast.hpp"

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

%type <branch> BODY
%type <node> DATA_TYPES STATEMENT BLOCK EXPR TERM UNARY FACTOR LINE DECLARATION
%type <node> HEAD

%start ROOT

%%
/* Extracts AST */
ROOT
	: HEAD { g_root =  $1;};


//HEAD OF FUNCTIONS

HEAD
	: DATA_TYPES IDENTIFIER '(' ')' BLOCK		{$$ = new Function($2, $5);}

BLOCK
	: '{' BODY '}'			{$$ = new Block($2);}

BODY
	: LINE BODY		{$$ = concat_list($1,$2);}
	| LINE				{$$ = init_list($1);}

LINE
	: STATEMENT		{$$ = $1;}
	| DECLARATION	{$$ = $1;}

STATEMENT
	: RETURN EXPR ';'			{$$ = new Return($2);}

DECLARATION
	: IDENTIFIER '=' EXPR ';'				{$$ = new Declaration((new Variable(*$1)),$3);} //temporary need to change
	| DATA_TYPES IDENTIFIER ';'
	| DATA_TYPES IDENTIFIER '=' EXPR ';'	{$$ = new Declaration((new Variable(*$2)),$4);} //temporary need to change



//EXPRESSIONS

EXPR
	: TERM              { $$ = $1; }
    | EXPR '+' EXPR 	{ $$ = new AddOperator($1, $3); }
    | EXPR '-' EXPR 	{ $$ = new SubOperator($1, $3); }
	| STRING_LITERAL	// need to define

TERM
	: UNARY             { $$ = $1; }
    | TERM '*' TERM     { $$ = new MulOperator($1, $3); }
    | TERM '/' TERM   	{ $$ = new DivOperator($1, $3); }

UNARY
	: FACTOR	  		{$$ = $1; }
	| '-' FACTOR  		{ $$ = new NegOperator($2); }


FACTOR
	: CONSTANT     		{$$ = new Number( $1 );}
    | '(' EXPR ')' 		{ $$ = $2;}
    | IDENTIFIER 		{$$ = new Variable( *$1 );}








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

