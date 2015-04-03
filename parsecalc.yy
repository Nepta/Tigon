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
}

%expect 0
%left "+" "-"
%left "*" "/"

%token <int> INT "number"
%type <int> exp line

%printer { yyo << $$; } <int>

%token
  LPAREN "("
  MINUS "-"
  PLUS "+"
  RPAREN ")"
  SLASH "/"
  STAR  "*"
  EOL "end of line"
  EOF 0
%%
input:
  %empty
| input line  { std::cout << (new PrettyPrinter())->visite($2) << std::endl; }
;

line:
  EOL       { $$ = -1; }
| exp EOL   { $$ = $1; }
| error EOL { $$ = 666; yyerrok; }
;

exp:
  exp "+" exp  { $$ = new Addition($1,$3); }
| exp "-" exp  { $$ = new Subtraction($1,$3); }
| exp "*" exp  { $$ = new Multiplication($1,$3); }
| exp "/" exp  {
//                 if ($3)
                   $$ = new Division($1,$3);
//                 else
//                   {
//                     yy::parser::error(@3, "division by 0");
//                     yyerror;
//                   }
               }
| "(" exp ")"  { $$ = $2; }
| "(" error ")"{ $$ = 777; }
| INT          { $$ = $1; }
;

%%

void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << loc << msg << std::endl;
	nerrs++;
}

int main(){
//%	yydebug = !!getenv("YYDEBUG");
	unsigned nerrs = 0;
	yy::parser p(nerrs);
	p.set_debug_level(!!getenv("YYDEBUG"));
	p.parse();
//%	nerrs += !!yyparse(&nerrs);
	return !!nerrs;
}
