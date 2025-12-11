%{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex();
    void yyerror(const char *s);
    extern FILE *yyin;
    extern char *yytext;

    int sym[26]; 
%}

%token NUMBER DEKHAO DHORI VARIABLE ASSIGN
%token PLUS MINUS MUL DIV LPAREN RPAREN SEMICOLON

%left PLUS MINUS
%left MUL DIV

%%

program:
    | program statement
    ;

statement:
    DEKHAO LPAREN expression RPAREN SEMICOLON {
        printf("Output: %d\n", $3);
    }
    | DHORI VARIABLE ASSIGN expression SEMICOLON {
        sym[$2] = $4; 
    }
    ;

expression:
    NUMBER                  { $$ = $1; }
    | VARIABLE              { $$ = sym[$1]; }
    
    /* NIcher Line gulo Fixed kora hoyeche ($2 er bodole $3 hobe) */
    | expression PLUS expression  { $$ = $1 + $3; }  
    | expression MINUS expression { $$ = $1 - $3; }
    | expression MUL expression   { $$ = $1 * $3; }
    
    | expression DIV expression   { 
        if($3 == 0) { yyerror("Divide by zero!"); $$ = 0; }
        else $$ = $1 / $3; 
    }
    | LPAREN expression RPAREN    { $$ = $2; }
    ;

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename.laxx>\n", argv[0]);
        return 1;
    }
    FILE *myfile = fopen(argv[1], "r");
    if (!myfile) {
        printf("Error opening file.\n");
        return 1;
    }
    yyin = myfile;
    
    for(int i=0; i<26; i++) sym[i] = 0;

    yyparse();
    fclose(myfile);
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at token '%s'\n", s, yytext);
}