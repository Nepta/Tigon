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
#include "Ast/Control/PrettyPrinter.h"
#include "Ast/Control/Interpreter.h"
}

%{
#include "Ast/Data/Visitable.h"
void (*processExp)(Visitable*);
%}

%expect 0
%left "+" "-"
%left "*" "/"

%token <int> INT "number"
%token <std::string> STRING "string"
%type <Visitable*> exp line

%printer { yyo << $$; } <int>

%token
  LPAREN	"("
  MINUS	"-"
  PLUS	"+"
  RPAREN	")"
  SLASH	"/"
  STAR	"*"
  IF		"if"
  THEN	"then"
  END		"end"
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
  exp "+" exp				{ $$ = new Addition($1,$3); }
| exp "-" exp				{ $$ = new Subtraction($1,$3); }
| exp "*" exp				{ $$ = new Multiplication($1,$3); }
| exp "/" exp				{ $$ = new Division($1,$3); }
| "(" exp ")"				{ $$ = $2; }
| IF exp THEN exp END	{ $$ = new If($2,$4); }
| "(" error ")"			{ $$ = new Int(777); }
| INT							{ $$ = new Int($1); }
| STRING						{ $$ = new String($1); }
;

%%

void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << loc << msg << std::endl;
	nerrs++;
}

void interpreter(Visitable* v){
	Interpreter i(*v);
	std::cout << i << std::endl;
}

void prettyPrinter(Visitable* v){
	PrettyPrinter p(*v);
	std::cout << p << std::endl;
}

int main(){
//%	yydebug = !!getenv("YYDEBUG");
	if(!!getenv("YYPRINT")){
		processExp = prettyPrinter;
	}else{
		processExp = interpreter;
	}
	unsigned nerrs = 0;
	yy::parser p(nerrs);
	p.set_debug_level(!!getenv("YYDEBUG"));
	p.parse();
//%	nerrs += !!yyparse(&nerrs);
	return !!nerrs;
}
