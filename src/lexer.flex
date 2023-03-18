%option noyywrap
%{
	// Avoid error "error: `fileno' was not declared in this scope"
	//extern "C" int fileno(FILE *stream);
	#include "parser.tab.hpp"
	#include <string>

	//lexing hack
	std::map<std::string, std::string> type_map;

	void update_type_map(std::string identifier, std::string type){
		type_map[identifier] = type;
	}


	auto check_type_map (std::string identifier){
		if (type_map.count(identifier)){
			if 		(type_map[identifier] == "void")		{ return(VOID);}
			else if (type_map[identifier] == "int")			{ return(INT); }
			else if (type_map[identifier] == "long")		{ return(LONG); }
			else if (type_map[identifier] == "short")		{ return(SHORT); }
			else if (type_map[identifier] == "double")		{ return(DOUBLE); }
			else if (type_map[identifier] == "float")		{ return(FLOAT); }
			else if (type_map[identifier] == "char")		{ return(CHAR); }
			else 	{std::cerr<< "Aliasing unknown datatype"<<std::endl; exit(1);}	//This shouldn't happen lol
		}
		return IDENTIFIER;
	}
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%%
"auto"			{ return(AUTO); }
"break"			{ return(BREAK); }
"case"			{ return(CASE); }
"continue"		{ return(CONTINUE); }
"default"		{ return(DEFAULT); }
"do"			{ return(DO); }
"else"			{ return(ELSE); }
"enum"			{ return(ENUM); }
"extern"		{ return(EXTERN); }
"for"			{ return(FOR); }
"goto"			{ return(GOTO); }
"if"			{ return(IF); }
"register"		{ return(REGISTER); }
"return"		{ return(RETURN); }
"signed"		{ return(SIGNED); }
"sizeof"		{ return(SIZEOF); }
"static"		{ return(STATIC); }
"struct"		{ return(STRUCT); }
"switch"		{ return(SWITCH); }
"typedef"		{ return(TYPEDEF); }
"union"			{ return(UNION); }
"unsigned"		{ return(UNSIGNED); }
"volatile"		{ return(VOLATILE); }
"while"			{ return(WHILE); }

"..."			{ return(ELLIPSIS); }

">>="			{ return(RIGHT_ASSIGN); }
"<<="			{ return(LEFT_ASSIGN); }
"+="			{ return(ADD_ASSIGN); }
"-="			{ return(SUB_ASSIGN); }
"*="			{ return(MUL_ASSIGN); }
"/="			{ return(DIV_ASSIGN); }
"%="			{ return(MOD_ASSIGN); }
"&="			{ return(AND_ASSIGN); }
"^="			{ return(XOR_ASSIGN); }
"|="			{ return(OR_ASSIGN); }

">>"			{ return(RIGHT_OP); }
"<<"			{ return(LEFT_OP); }
"++"			{ return(INC_OP); }
"--"			{ return(DEC_OP); }
"->"			{ return(PTR_OP); }
"&&"			{ return(AND_OP); }
"||"			{ return(OR_OP); }
"<="			{ return(LE_OP); }
">="			{ return(GE_OP); }
"=="			{ return(EQ_OP); }
"!="			{ return(NE_OP); }

";"			    { return(';'); }
("{"|"<%")		{ return('{'); }
("}"|"%>")		{ return('}'); }
","				{ return(','); }
":"				{ return(':'); }
"="				{ return('='); }
"("				{ return('('); }
")"				{ return(')'); }
("["|"<:")		{ return('['); }
("]"|":>")		{ return(']'); }
"."				{ return('.'); }
"&"				{ return('&'); }
"!"				{ return('!'); }
"~"				{ return('~'); }
"-"				{ return('-'); }
"+"				{ return('+'); }
"*"				{ return('*'); }
"/"				{ return('/'); }
"%"				{ return('%'); }
"<"				{ return('<'); }
">"				{ return('>'); }
"^"				{ return('^'); }
"|"				{ return('|'); }
"?"				{ return('?'); }


"void"			{ return(VOID); }
"int"			{ return(INT); }
"long"			{ return(LONG); }
"short"			{ return(SHORT); }
"double"		{ return(DOUBLE); }
"float"			{ return(FLOAT); }
"char"			{ return(CHAR); }



{L}({L}|{D})*				{ yylval.string=new std::string(yytext); return check_type_map(std::string(yytext));}

0[xX]{H}+{IS}?				{ yylval.number=std::stold(yytext); return(CONSTANT); } //
0{D}+{IS}?					{ yylval.number=std::stold(yytext); return(CONSTANT); } //
{D}+{IS}?					{ yylval.number=std::stold(yytext); return(CONSTANT); } //need to fix data types everywhere
{D}+{E}{FS}?				{ yylval.number=std::stold(yytext); return(CONSTANT); } //
{D}*"."{D}+({E})?{FS}?		{ yylval.number=std::stold(yytext); return(CONSTANT); } //
{D}+"."{D}*({E})?{FS}?		{ yylval.number=std::stold(yytext); return(CONSTANT); } //

L?'(\\.|[^\\'])+'			{ yylval.string=new std::string(yytext); return CHAR_LITERAL; }
L?\"(\\.|[^\\"])*\"	 		{ yylval.string=new std::string(yytext); return STRING_LITERAL; }

"//"(.)*     								{;}					// Single-line comment
"/*"([^*]|\n|\r|("*"+[^*/]))*("*"+"/")?  	{;}					/* Multi-line comment */

[ \t\r\n]+		 			{;}
.				 			{;}

%%

void yyerror (char const *s){
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
