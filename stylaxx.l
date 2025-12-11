%option noyywrap

%{
    #include "stylaxx.tab.h"
    #include <string.h>
    #include <stdlib.h>
%}

%%

"dekhao"    { return DEKHAO; }
"dhori"     { return DHORI; }

[a-zA-Z][a-zA-Z0-9]* { 
                yylval.strVal = strdup(yytext); 
                return VARIABLE; 
            }

[0-9]+\.[0-9]+ { 
                yylval.floatVal = atof(yytext); 
                return FLOAT_NUM; 
            }

[0-9]+      { 
                yylval.intVal = atoi(yytext); 
                return INT_NUM; 
            }

\"[^"]*\"   { 
                /* String handling logic */
                yylval.strVal = strdup(yytext + 1); 
                if (yylval.strVal[strlen(yylval.strVal)-1] == '"') {
                    yylval.strVal[strlen(yylval.strVal)-1] = 0; 
                }
                return STRING_LIT; 
            }

"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"("         { return LPAREN; }
")"         { return RPAREN; }
";"         { return SEMICOLON; }

[ \t\n\r]   { /* Ignore whitespace */ }

.           { printf("Unknown Character: %s\n", yytext); }

%%