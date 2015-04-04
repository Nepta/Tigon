/* Prologue. */
%option noyywrap

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
"+"		return yy::parser::token::TOK_PLUS;
"-"		return yy::parser::token::TOK_MINUS;
"*"		return yy::parser::token::TOK_STAR;
"/"		return yy::parser::token::TOK_SLASH;
"("		return yy::parser::token::TOK_LPAREN;
")"		return yy::parser::token::TOK_RPAREN;
"if"		return yy::parser::token::TOK_IF;
"then"	return yy::parser::token::TOK_THEN;
"end"		return yy::parser::token::TOK_END;
[0-9]+	yylval->build<int>(strtol(yytext, 0, 10)) ; return yy::parser::token::TOK_INT;
" "+		yylloc->step(); continue;
"\n"		yylloc->lines(1); yylloc->columns(1); yylloc->step(); return yy::parser::token::TOK_EOL;
.			fprintf (stderr, "error: invalid character: %c\n", *yytext);
<<EOF>>	return yy::parser::token::TOK_EOF;
%%
/* Epilogue.  */
