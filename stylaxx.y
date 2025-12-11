%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    int yylex();
    void yyerror(const char *s);
    extern FILE *yyin;
    extern char *yytext;
%}

/* --- DATA STRUCTURES --- */
%code requires {
    typedef struct {
        int type;       // 0=INT, 1=FLOAT, 2=STRING
        int i_val;
        double f_val;
        char *s_val;
        int is_array;
        int *arr_vals;
        int arr_size;
    } Data;

    typedef enum { 
        NODE_CONST, NODE_VAR, NODE_OP, NODE_ASSIGN, 
        NODE_IF, NODE_WHILE, NODE_FOR, NODE_SEQ, NODE_PRINT, NODE_INPUT,
        NODE_ARRAY_DECL, NODE_ARRAY_ASSIGN, NODE_ARRAY_ACCESS,
        NODE_MATH_FUNC
    } NodeType;

    typedef struct Node {
        NodeType type;
        Data value;             
        char *varName;          
        char op;                
        int mathFuncType;       
        struct Node *left;      
        struct Node *right;     
        struct Node *cond;      
        struct Node *body;      
        struct Node *elseBody;  
    } Node;
}

%union {
    int intVal;
    double floatVal;
    char *strVal;
    Node *nodePtr;
}

%token <intVal> INT_NUM
%token <floatVal> FLOAT_NUM
%token <strVal> STRING_LIT VARIABLE
%token DEKHAO DHORI IF ELSE WHILE FOR INPUT
%token POW ROOT SIN COS TAN ABS
%token AND OR EQ NEQ GE LE GT LT ASSIGN PLUS MINUS MUL DIV MOD
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON LBRACKET RBRACKET COMMA

/* NOTICE: 'program' removed from type because it returns nothing */
%type <nodePtr> statement expression statement_list

%left OR
%left AND
%left EQ NEQ GE LE GT LT
%left PLUS MINUS
%left MUL DIV MOD

%{
    struct Symbol {
        char *name;
        Data data;
    };
    struct Symbol table[100];
    int count = 0;

    void set_var(char *name, Data d) {
        for(int i=0; i<count; i++) {
            if(strcmp(table[i].name, name) == 0) {
                if(table[i].data.is_array && !d.is_array) { /* protect array */ }
                else table[i].data = d;
                return;
            }
        }
        table[count].name = strdup(name);
        table[count].data = d;
        count++;
    }

    Data get_var(char *name) {
        for(int i=0; i<count; i++) {
            if(strcmp(table[i].name, name) == 0) return table[i].data;
        }
        printf("Runtime Error: Variable '%s' not found.\n", name);
        return (Data){0};
    }

    /* --- NODE HELPERS --- */
    Node* makeNum(int v) { Node *p = malloc(sizeof(Node)); p->type=NODE_CONST; p->value.type=0; p->value.i_val=v; return p; }
    Node* makeFloat(double v) { Node *p = malloc(sizeof(Node)); p->type=NODE_CONST; p->value.type=1; p->value.f_val=v; return p; }
    Node* makeStr(char *s) { Node *p = malloc(sizeof(Node)); p->type=NODE_CONST; p->value.type=2; p->value.s_val=s; return p; }
    Node* makeVar(char *n) { Node *p = malloc(sizeof(Node)); p->type=NODE_VAR; p->varName=n; return p; }
    
    Node* makeOp(Node *l, Node *r, char op) { 
        Node *p = malloc(sizeof(Node)); p->type=NODE_OP; p->left=l; p->right=r; p->op=op; return p; 
    }
    Node* makeAssign(char *n, Node *expr) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ASSIGN; p->varName=n; p->left=expr; return p;
    }
    Node* makePrint(Node *expr) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_PRINT; p->left=expr; return p;
    }
    Node* makeInput() {
        Node *p = malloc(sizeof(Node)); p->type=NODE_INPUT; return p;
    }
    Node* makeMath(int type, Node *l, Node *r) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_MATH_FUNC; p->mathFuncType=type; p->left=l; p->right=r; return p;
    }
    Node* makeSeq(Node *l, Node *r) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_SEQ; p->left=l; p->right=r; return p;
    }
    Node* makeIf(Node *cond, Node *ifB, Node *elseB) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_IF; p->cond=cond; p->body=ifB; p->elseBody=elseB; return p;
    }
    Node* makeWhile(Node *cond, Node *body) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_WHILE; p->cond=cond; p->body=body; return p;
    }
    Node* makeFor(Node *init, Node *cond, Node *incr, Node *body) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_FOR; p->left=init; p->cond=cond; p->right=incr; p->body=body; return p;
    }
    Node* makeArrayDecl(char *n, int size) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ARRAY_DECL; p->varName=n; p->value.i_val=size; return p;
    }
    Node* makeArrayAcc(char *n, Node *idx) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ARRAY_ACCESS; p->varName=n; p->left=idx; return p;
    }
    Node* makeArrayAss(char *n, Node *idx, Node *val) {
        Node *p = malloc(sizeof(Node)); p->type=NODE_ARRAY_ASSIGN; p->varName=n; p->left=idx; p->right=val; return p;
    }

    /* --- RUN ENGINE --- */
    Data run(Node *p) {
        if(!p) return (Data){0};
        
        switch(p->type) {
            case NODE_CONST: return p->value;
            case NODE_VAR:   return get_var(p->varName);
            
            case NODE_INPUT: {
                Data res = {0};
                double temp;
                scanf("%lf", &temp);
                if (temp == (int)temp) {
                    res.type = 0; res.i_val = (int)temp;
                } else {
                    res.type = 1; res.f_val = temp;
                }
                return res;
            }

            case NODE_MATH_FUNC: {
                Data v1 = run(p->left);
                Data v2 = (p->right) ? run(p->right) : (Data){0};
                double n1 = (v1.type==1)?v1.f_val:v1.i_val;
                double n2 = (v2.type==1)?v2.f_val:v2.i_val;
                Data res = {0}; res.type = 1;

                switch(p->mathFuncType) {
                    case 1: res.f_val = pow(n1, n2); break;
                    case 2: res.f_val = sqrt(n1); break;
                    case 3: res.f_val = sin(n1 * 3.1416 / 180); break;
                    case 4: res.f_val = cos(n1 * 3.1416 / 180); break;
                    case 5: res.f_val = tan(n1 * 3.1416 / 180); break;
                    case 6: res.f_val = abs((int)n1); res.type=0; break;
                }
                return res;
            }
            
            case NODE_OP: {
                Data v1 = run(p->left);
                Data v2 = run(p->right);
                Data res = {0};
                
                double n1 = (v1.type==1)?v1.f_val:v1.i_val;
                double n2 = (v2.type==1)?v2.f_val:v2.i_val;
                int isF = (v1.type==1 || v2.type==1);
                
                if(p->op=='+') { if(isF) {res.type=1; res.f_val=n1+n2;} else {res.type=0; res.i_val=(int)n1+(int)n2;} }
                if(p->op=='-') { if(isF) {res.type=1; res.f_val=n1-n2;} else {res.type=0; res.i_val=(int)n1-(int)n2;} }
                if(p->op=='*') { if(isF) {res.type=1; res.f_val=n1*n2;} else {res.type=0; res.i_val=(int)n1*(int)n2;} }
                if(p->op=='/') { 
                    if(n2==0) printf("Error: Div by Zero\n");
                    else if(isF) {res.type=1; res.f_val=n1/n2;} else {res.type=0; res.i_val=(int)n1/(int)n2;} 
                }
                if(p->op=='%') { res.type=0; res.i_val=(int)n1 % (int)n2; }

                if(p->op=='g') { res.type=0; res.i_val = (n1 > n2); }
                if(p->op=='l') { res.type=0; res.i_val = (n1 < n2); }
                if(p->op=='e') { res.type=0; res.i_val = (n1 == n2); }
                if(p->op=='!') { res.type=0; res.i_val = (n1 != n2); }
                if(p->op=='G') { res.type=0; res.i_val = (n1 >= n2); }
                if(p->op=='L') { res.type=0; res.i_val = (n1 <= n2); }

                if(p->op=='&') { res.type=0; res.i_val = (n1 && n2); }
                if(p->op=='|') { res.type=0; res.i_val = (n1 || n2); }

                return res;
            }

            case NODE_ASSIGN: {
                Data v = run(p->left);
                set_var(p->varName, v);
                return v;
            }
            case NODE_SEQ:
                run(p->left);
                run(p->right);
                return (Data){0};
            case NODE_PRINT: {
                Data v = run(p->left);
                if(v.type==0) printf("%d\n", v.i_val);
                else if(v.type==1) printf("%.2f\n", v.f_val);
                else if(v.type==2) printf("%s\n", v.s_val);
                return (Data){0};
            }
            case NODE_IF:
                if(run(p->cond).i_val) run(p->body);
                else if(p->elseBody) run(p->elseBody);
                return (Data){0};
            case NODE_WHILE:
                while(run(p->cond).i_val) run(p->body);
                return (Data){0};
            case NODE_FOR:
                run(p->left);               
                while(run(p->cond).i_val) { 
                    run(p->body);           
                    run(p->right);          
                }
                return (Data){0};

            case NODE_ARRAY_DECL: {
                Data d = {0}; d.is_array = 1; d.arr_size = p->value.i_val;
                d.arr_vals = (int*)calloc(d.arr_size, sizeof(int));
                set_var(p->varName, d); return (Data){0};
            }
            case NODE_ARRAY_ASSIGN: {
                Data idx = run(p->left); Data val = run(p->right); Data arr = get_var(p->varName);
                if(arr.is_array && idx.i_val < arr.arr_size) arr.arr_vals[idx.i_val] = val.i_val;
                return (Data){0}; 
            }
            case NODE_ARRAY_ACCESS: {
                Data idx = run(p->left); Data arr = get_var(p->varName); Data res = {0};
                if(arr.is_array && idx.i_val < arr.arr_size) { res.type = 0; res.i_val = arr.arr_vals[idx.i_val]; }
                return res;
            }
        }
        return (Data){0};
    }
%}

%%

program:
    /* empty */
    | program statement { run($2); }
    ;

statement:
    DEKHAO LPAREN expression RPAREN SEMICOLON { $$ = makePrint($3); }
    | DHORI VARIABLE ASSIGN expression SEMICOLON { $$ = makeAssign($2, $4); }
    | DHORI VARIABLE LBRACKET INT_NUM RBRACKET SEMICOLON { $$ = makeArrayDecl($2, $4); }
    | VARIABLE LBRACKET expression RBRACKET ASSIGN expression SEMICOLON { $$ = makeArrayAss($1, $3, $6); }
    
    | IF LPAREN expression RPAREN LBRACE statement_list RBRACE { $$ = makeIf($3, $6, NULL); }
    | IF LPAREN expression RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE { $$ = makeIf($3, $6, $10); }
    | WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE { $$ = makeWhile($3, $6); }
    
    | FOR LPAREN statement expression SEMICOLON statement RPAREN LBRACE statement_list RBRACE { 
        $$ = makeFor($3, $4, $6, $9); 
    }
    | VARIABLE ASSIGN expression SEMICOLON { $$ = makeAssign($1, $3); }
    ;

statement_list:
    statement { $$ = $1; }
    | statement_list statement { $$ = makeSeq($1, $2); }
    ;

expression:
    INT_NUM                 { $$ = makeNum($1); }
    | FLOAT_NUM             { $$ = makeFloat($1); }
    | STRING_LIT            { $$ = makeStr($1); }
    | VARIABLE              { $$ = makeVar($1); }
    | INPUT LPAREN RPAREN   { $$ = makeInput(); }
    | VARIABLE LBRACKET expression RBRACKET { $$ = makeArrayAcc($1, $3); }
    
    | POW LPAREN expression COMMA expression RPAREN { $$ = makeMath(1, $3, $5); }
    | ROOT LPAREN expression RPAREN { $$ = makeMath(2, $3, NULL); }
    | SIN LPAREN expression RPAREN { $$ = makeMath(3, $3, NULL); }
    | COS LPAREN expression RPAREN { $$ = makeMath(4, $3, NULL); }
    | TAN LPAREN expression RPAREN { $$ = makeMath(5, $3, NULL); }
    | ABS LPAREN expression RPAREN { $$ = makeMath(6, $3, NULL); }

    | expression PLUS expression  { $$ = makeOp($1, $3, '+'); }
    | expression MINUS expression { $$ = makeOp($1, $3, '-'); }
    | expression MUL expression   { $$ = makeOp($1, $3, '*'); }
    | expression DIV expression   { $$ = makeOp($1, $3, '/'); }
    | expression MOD expression   { $$ = makeOp($1, $3, '%'); }
    
    | expression GT expression    { $$ = makeOp($1, $3, 'g'); }
    | expression LT expression    { $$ = makeOp($1, $3, 'l'); }
    | expression EQ expression    { $$ = makeOp($1, $3, 'e'); }
    | expression NEQ expression   { $$ = makeOp($1, $3, '!'); }
    | expression GE expression    { $$ = makeOp($1, $3, 'G'); }
    | expression LE expression    { $$ = makeOp($1, $3, 'L'); }
    
    | expression AND expression   { $$ = makeOp($1, $3, '&'); }
    | expression OR expression    { $$ = makeOp($1, $3, '|'); }
    
    | LPAREN expression RPAREN    { $$ = $2; }
    ;

%%

int main(int argc, char *argv[]) {
    if (argc < 2) { printf("Usage: %s <file>\n", argv[0]); return 1; }
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
void yyerror(const char *s) { fprintf(stderr, "Error: %s near '%s'\n", s, yytext); }