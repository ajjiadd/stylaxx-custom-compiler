%option noyywrap

%{
    #include "stylaxx.tab.h"
    #include <string.h>
    #include <stdlib.h>
%}

%%

\/\/.* { /* Single line comment ignore koro */ }

"dekhao"    { return DEKHAO; }
"dhori"     { return DHORI; }
"nio"       { return INPUT; }

"jodi"      { return IF; }
"nahole"    { return ELSE; }
"jotokhon"  { return WHILE; }
"ghuro"     { return FOR; }

"pow"       { return POW; }
"root"      { return ROOT; }
"sin"       { return SIN; }
"cos"       { return COS; }
"tan"       { return TAN; }
"abs"       { return ABS; }

[a-zA-Z][a-zA-Z0-9]* { 
                yylval.strVal = strdup(yytext); 
                return VARIABLE; 
            }

[0-9]+\.[0-9]+ { yylval.floatVal = atof(yytext); return FLOAT_NUM; }
[0-9]+         { yylval.intVal = atoi(yytext); return INT_NUM; }

\"[^"]*\"   { 
                yylval.strVal = strdup(yytext + 1); 
                if (yylval.strVal[strlen(yylval.strVal)-1] == '"') 
                    yylval.strVal[strlen(yylval.strVal)-1] = 0; 
                return STRING_LIT; 
            }

"&&"        { return AND; }
"||"        { return OR; }
"=="        { return EQ; }
"!="        { return NEQ; }
">="        { return GE; }
"<="        { return LE; }
">"         { return GT; }
"<"         { return LT; }

"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"%"         { return MOD; }

"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }
";"         { return SEMICOLON; }
","         { return COMMA; }

[ \t\n\r]   { /* Ignore whitespace */ }
.           { printf("Unknown character: %s\n", yytext); }

%%