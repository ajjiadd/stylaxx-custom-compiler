%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Forward declarations needed for C compiler
    int yylex();
    void yyerror(const char *s);
    extern FILE *yyin;
    extern char *yytext;
%}

/* --- PART 1: Data Structure Definition (MUST BE HERE) --- */
%code requires {
    typedef struct {
        int type;       // 0=INT, 1=FLOAT, 2=STRING
        int i_val;
        double f_val;
        char *s_val;
    } Data;
}

/* --- PART 2: Union Definition --- */
%union {
    int intVal;
    double floatVal;
    char *strVal;
    Data dataVal;   // Uses Data defined above
}

/* --- PART 3: Token Declarations --- */
%token <intVal> INT_NUM
%token <floatVal> FLOAT_NUM
%token <strVal> STRING_LIT VARIABLE
%token DEKHAO DHORI ASSIGN PLUS MINUS MUL DIV LPAREN RPAREN SEMICOLON

%type <dataVal> expression

%left PLUS MINUS
%left MUL DIV

/* --- PART 4: C Code & Helper Functions --- */
%{
    // Symbol Table
    struct Symbol {
        char *name;
        Data data;
    };

    struct Symbol table[100];
    int count = 0;

    // Helper: Set Value
    void set_value(char *name, Data d) {
        for(int i=0; i<count; i++) {
            if(strcmp(table[i].name, name) == 0) {
                table[i].data = d;
                return;
            }
        }
        table[count].name = strdup(name);
        table[count].data = d;
        count++;
    }

    // Helper: Get Value
    Data get_value(char *name) {
        for(int i=0; i<count; i++) {
            if(strcmp(table[i].name, name) == 0) {
                return table[i].data;
            }
        }
        printf("Error: Variable '%s' not found!\n", name);
        Data empty = {0, 0, 0.0, NULL};
        return empty;
    }

    // Helper: Calculate Logic
    Data calculate(Data a, Data b, char op) {
        Data res;
        
        // String handling restriction
        if(a.type == 2 || b.type == 2) {
            printf("Error: Cannot do math with strings!\n");
            res.type = 0; res.i_val = 0; return res;
        }

        // Int vs Float Logic
        if(a.type == 0 && b.type == 0) { // Both INT
            res.type = 0;
            if(op == '+') res.i_val = a.i_val + b.i_val;
            if(op == '-') res.i_val = a.i_val - b.i_val;
            if(op == '*') res.i_val = a.i_val * b.i_val;
            if(op == '/') {
                if(b.i_val == 0) { printf("Error: Div by 0\n"); res.i_val=0; }
                else res.i_val = a.i_val / b.i_val;
            }
        }
        else { // Mixed or Float
            res.type = 1;
            double v1 = (a.type == 0) ? (double)a.i_val : a.f_val;
            double v2 = (b.type == 0) ? (double)b.i_val : b.f_val;

            if(op == '+') res.f_val = v1 + v2;
            if(op == '-') res.f_val = v1 - v2;
            if(op == '*') res.f_val = v1 * v2;
            if(op == '/') {
                 if(v2 == 0) { printf("Error: Div by 0\n"); res.f_val=0; }
                 else res.f_val = v1 / v2;
            }
        }
        return res;
    }
%}

%%

/* --- PART 5: Grammar Rules --- */
program:
    | program statement
    ;

statement:
    DEKHAO LPAREN expression RPAREN SEMICOLON {
        if ($3.type == 0) printf("Output (Int): %d\n", $3.i_val);
        else if ($3.type == 1) printf("Output (Float): %.2f\n", $3.f_val);
        else if ($3.type == 2) printf("Output (Text): %s\n", $3.s_val);
    }
    | DHORI VARIABLE ASSIGN expression SEMICOLON {
        set_value($2, $4);
    }
    ;

expression:
    INT_NUM                 { $$.type = 0; $$.i_val = $1; }
    | FLOAT_NUM             { $$.type = 1; $$.f_val = $1; }
    | STRING_LIT            { $$.type = 2; $$.s_val = $1; }
    | VARIABLE              { $$ = get_value($1); }
    
    | expression PLUS expression  { $$ = calculate($1, $3, '+'); }
    | expression MINUS expression { $$ = calculate($1, $3, '-'); }
    | expression MUL expression   { $$ = calculate($1, $3, '*'); }
    | expression DIV expression   { $$ = calculate($1, $3, '/'); }
    
    | LPAREN expression RPAREN    { $$ = $2; }
    ;

%%

/* --- PART 6: Main Function --- */
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
    yyparse();
    fclose(myfile);
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at token '%s'\n", s, yytext);
}