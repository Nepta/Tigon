/* Prologue. */
%option noyywrap
%option nounput
%option noinput

%{
#include "parsecalc.hpp"
#include "location.hh"

# define YY_USER_ACTION                         \
  yylloc->columns(yyleng);


%}
%%
%{
  yylloc->step();
%}
"+"							return yy::parser::token::TOK_PLUS;
"-"							return yy::parser::token::TOK_MINUS;
"*"							return yy::parser::token::TOK_STAR;
"/"							return yy::parser::token::TOK_SLASH;
"("							return yy::parser::token::TOK_LPAREN;
")"							return yy::parser::token::TOK_RPAREN;
":="    						return yy::parser::token::TOK_ASSIGN;
"="							return yy::parser::token::TOK_EQUAL;
"<>"							return yy::parser::token::TOK_NOTEQUAL;
"<"							return yy::parser::token::TOK_LESS;
"<="							return yy::parser::token::TOK_LESSEQUAL;
">"							return yy::parser::token::TOK_GREATER;
">="							return yy::parser::token::TOK_GREATEREQUAL;
";"							return yy::parser::token::TOK_SEQUENCE;
\".*\"   					yylval->build<std::string>(yytext) ; return yy::parser::token::TOK_STRING;
"if"							return yy::parser::token::TOK_IF;
"then"						return yy::parser::token::TOK_THEN;
"else"						return yy::parser::token::TOK_ELSE;
[0-9]+						yylval->build<int>(strtol(yytext, 0, 10)) ; return yy::parser::token::TOK_INT;
"var"    					return yy::parser::token::TOK_VAR;
"while"						return yy::parser::token::TOK_WHILE;
"do"							return yy::parser::token::TOK_DO;

[_a-zA-Z][_a-zA-Z0-9]*	yylval->build<std::string>(yytext) ; return yy::parser::token::TOK_VARNAME;
" "+							yylloc->step(); continue;
"\n"							yylloc->lines(1); yylloc->columns(1); yylloc->step(); return yy::parser::token::TOK_EOL;
.								fprintf (stderr, "error: invalid character: %c\n", *yytext);
<<EOF>>						return yy::parser::token::TOK_EOF;
%%
/* Epilogue.  */
