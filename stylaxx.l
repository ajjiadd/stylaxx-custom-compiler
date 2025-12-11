%option noyywrap

%{
    #include "stylaxx.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
%}

%%

"print"     { return PRINT; }       /* Keyword to print output */
[0-9]+      { yylval = atoi(yytext); return NUMBER; } /* Detect numbers */
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"("         { return LPAREN; }
")"         { return RPAREN; }
";"         { return SEMICOLON; }
[ \t\n]     { /* Ignore whitespace and newlines */ }
.           { printf("Unknown Character: %s\n", yytext); }

%%