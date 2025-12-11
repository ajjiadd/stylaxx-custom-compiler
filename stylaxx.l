%option noyywrap

%{
    #include "stylaxx.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
%}

%%

"dekhao"    { return DEKHAO; }
"dhori"     { return DHORI; }

[a-z]       { 
                yylval = *yytext - 'a'; 
                return VARIABLE; 
            }

[0-9]+      { yylval = atoi(yytext); return NUMBER; }

"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"("         { return LPAREN; }
")"         { return RPAREN; }
";"         { return SEMICOLON; }

[ \t\n\r]   { /* Ekhane \r add kora hoyeche Windows fix er jonno */ }

.           { printf("Unknown Character: %s\n", yytext); }

%%