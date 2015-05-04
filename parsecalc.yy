%defines
%error-verbose
%debug
%language "c++"
%define api.token.prefix {TOK_}
%define api.value.type variant

%locations
%parse-param { unsigned& nerrs }

%code provides
{
#define YY_DECL                                 \
  yy::parser::token_type yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc)
  YY_DECL;
}

%code requires
{
#include "Ast/Data/Operation/Addition.h"
#include "Ast/Data/Operation/Subtraction.h"
#include "Ast/Data/Operation/Multiplication.h"
#include "Ast/Data/Operation/Division.h"
#include "Ast/Data/Operation/Sequence.h"
#include "Ast/Control/PrettyPrinter.h"
#include "Ast/Control/Interpreter.h"
#include "Ast/Data/VariableList.h"
#include "Ast/Data/Operation/ReadVariable.h"
#include "Ast/Data/Print.h"
extern VariableList variableList_;
}

%{
#include "Ast/Data/Visitable.h"
#include "Ast/Data/VariableList.h"

void (*processExp)(Visitable*);
VariableList variableList_;
%}

%expect 0
%precedence "do"
%left ";"
%precedence ":="
%left "+" "-"
%left "*" "/"
%right "then" "else" //http://stackoverflow.com/questions/12731922/reforming-the-grammar-to-remove-shift-reduce-conflict-in-if-then-else/12734499#12734499
%nonassoc "=" "<>" "<" ">" "<=" ">="

%token <int> INT "number"
%token <std::string> STRING "string"
%token <std::string> VARNAME "varname"
%type <Visitable*> exp line

%printer { yyo << $$; } <int>

%token
  PRINT	"§"
  SEQUENCE ";"
  LPAREN	"("
  MINUS	"-"
  PLUS	"+"
  RPAREN	")"
  SLASH	"/"
  STAR	"*"
  ASSIGN	":="
  EQUAL	"="
  NOTEQUAL "<>"
  LESS "<"
  LESSEQUAL "<="
  GREATER ">"
  GREATEREQUAL ">="
  IF		"if"
  THEN	"then"
  ELSE	"else"
  VAR		"var"
  WHILE	"while"
  DO		"do"
  EOL		"end of line"
  EOF 0

%%
input:
  %empty
| input line  { processExp($2); }
;

line:
  EOL       { $$ = new Int(-1); }
| exp EOL   { $$ = $1; }
| error EOL { $$ = new Int(666); yyerrok; }
;

exp:
  exp "+" exp							{ $$ = new Addition($1,$3); }
| exp "-" exp							{ $$ = new Subtraction($1,$3); }
| exp "*" exp							{ $$ = new Multiplication($1,$3); }
| exp "/" exp							{ $$ = new Division($1,$3); }
| exp "=" exp							{ $$ = new Equal($1,$3); }
| exp "<>" exp							{ $$ = new NotEqual($1,$3); }
| exp "<" exp							{ $$ = new Less($1,$3); }
| exp "<=" exp							{ $$ = new LessEqual($1,$3); }
| exp ">" exp							{ $$ = new Greater($1,$3); }
| exp ">=" exp							{ $$ = new GreaterEqual($1,$3); }
| exp ";" exp							{ $$ = new Sequence($1,$3); }
| "(" exp ")"							{ $$ = $2; }
| "if" exp "then" exp "else" exp	{ $$ = new If($2,$4,$6); }
| "if" exp "then" exp				{ $$ = new If($2,$4,new Int(0)); }
| "while" exp "do" exp				{ $$ = new While($2,$4); }
| "(" error ")"						{ $$ = new Int(777); }
| "number"								{ $$ = new Int($1); }
| "string"								{ $$ = new String($1); }
| "varname" ":=" exp					{ $$ = new Affectation($1,$3); }
| "varname"								{ $$ = new ReadVariable($1); }
| "§" "varname"						{ $$ = new Print($2);}
;

%%

void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << loc << ": " << msg << std::endl;
	nerrs++;
}

void verboseInterpreter(Visitable* v){
	Interpreter i(variableList_);
	v->accept(i);
	std::cout << "@" << i << std::endl;
}

void interpreter(Visitable* v){
	Interpreter i(variableList_);
	v->accept(i);
}

void verbosePrettyPrinter(Visitable* v){
	PrettyPrinter p(variableList_);
	v->accept(p);
	std::cout << "@" << p << std::endl;
}

void prettyPrinter(Visitable* v){
	PrettyPrinter p(variableList_);
	v->accept(p);
}

int main(int argc, char* argv[]){
//%	yydebug = !!getenv("YYDEBUG");
	if(argc == 2){
		std::string command(argv[1]);
		if(command == "-v"){
			if(!!getenv("YYEVAL")){
				processExp = verboseInterpreter;
			}else{
				processExp = verbosePrettyPrinter;
			}
		}
	}else{
		if(!!getenv("YYEVAL")){
			processExp = interpreter;
		}else{
			processExp = prettyPrinter;
		}
	}
	unsigned nerrs = 0;
	yy::parser p(nerrs);
	p.set_debug_level(!!getenv("YYDEBUG"));
	p.parse();
//%	nerrs += !!yyparse(&nerrs);
	return !!nerrs;
}

