%defines
%error-verbose
%debug
%language "c++"

%locations
%parse-param { unsigned& nerrs }
%union
{
  int ival;
}

%code provides
{
#define YY_DECL                                 \
  yy::parser::token_type yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc)
  YY_DECL;
}

%expect 0
%left "+" "-"
%left "*" "/"

%token <ival> INT "number"
%type <ival> exp line

%printer { yyo << $$; } <ival>

%token
  LPAREN "("
  MINUS "-"
  PLUS "+"
  RPAREN ")"
  SLASH "/"
  STAR  "*"
  EOL "end of line"
%%
input:
  %empty
| input line  { std::cout << $2; }
;

line:
  EOL       { $$ = -1; }
| exp EOL   { $$ = $1; }
| error EOL { $$ = 666; yyerrok; }
;

exp:
  exp "+" exp  { $$ = $1 + $3; }
| exp "-" exp  { $$ = $1 - $3; }
| exp "*" exp  { $$ = $1 * $3; }
| exp "/" exp  {
                 if ($3)
                   $$ = $1 / $3;
                 else
                   {
                     yy::parser::error(@3, "division by 0");
                     YYERROR;
                   }
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
