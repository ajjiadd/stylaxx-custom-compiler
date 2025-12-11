%{
    #include <stdio.h>
    #include <stdlib.h>

    // Function prototypes
    int yylex();
    void yyerror(const char *s);
    
    // File pointer for reading input
    extern FILE *yyin;
%}

/* Token definitions received from Lexer */
%token NUMBER PRINT
%token PLUS MINUS MUL DIV LPAREN RPAREN SEMICOLON

/* Operator Precedence (BODMAS logic) */
%left PLUS MINUS
%left MUL DIV

%%

/* Grammar Rules */
program:
    | program statement
    ;

statement:
    PRINT LPAREN expression RPAREN SEMICOLON {
        printf("Stylaxx Output: %d\n", $3);
    }
    ;

expression:
    NUMBER                  { $$ = $1; }
    | expression PLUS expression  { $$ = $1 + $2; }
    | expression MINUS expression { $$ = $1 - $2; }
    | expression MUL expression   { $$ = $1 * $2; }
    | expression DIV expression   { 
        if($3 == 0) {
            yyerror("Error: Division by zero!");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    | LPAREN expression RPAREN    { $$ = $2; }
    ;

%%

/* Main Function */
int main(int argc, char *argv[]) {
    // Check if the user provided a file name
    if (argc < 2) {
        printf("Usage: %s <filename.laxx>\n", argv[0]);
        return 1;
    }

    // Open the file provided in argument
    FILE *myfile = fopen(argv[1], "r");
    if (!myfile) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    // Point flex to read from this file
    yyin = myfile;

    // Start parsing
    printf("Parsing file: %s ...\n", argv[1]);
    yyparse();
    
    fclose(myfile);
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}