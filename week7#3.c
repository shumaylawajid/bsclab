#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    double data[MAX];
    int top;
};

void push(struct Stack *s, double val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}

double pop(struct Stack *s) {
    if (s->top != -1) {
        return s->data[(s->top)--];
    }
    return 0.0;
}

/* Helper to show stack contents */
void printStack(struct Stack s) {
    int i; /* Declared outside for loop for older standards */
    printf("[ ");
    for (i = 0; i <= s.top; i++) {
        printf("%.2f ", s.data[i]);
    }
    printf("]");
}

int main() {
    struct Stack st;
    char exp[MAX];
    char symbol[20];
    char eval_str[50];
    char *p;
    double n1, n2, res;
    int len;
    
    st.top = -1;

    printf("Enter postfix expression (use commas): ");
    scanf("%s", exp);

    printf("\n%-10s | %-25s | %-20s\n", "Symbol", "Evaluation", "Stack Status");
    printf("----------------------------------------------------------------------\n");

    p = exp;
    while (*p != '\0') {
        if (*p == ',' || isspace(*p)) {
            p++;
            continue;
        }

        if (isdigit(*p)) {
            char *endPtr;
            double num = strtod(p, &endPtr);
            
            len = (int)(endPtr - p);
            strncpy(symbol, p, len);
            symbol[len] = '\0';
            
            push(&st, num);
            printf("%-10s | %-25s | ", symbol, "-");
            p = endPtr;
        } 
        else {
            n2 = pop(&st);
            n1 = pop(&st);
            res = 0;
            
            switch (*p) {
                case '+': res = n1 + n2; break;
                case '-': res = n1 - n2; break;
                case '*': res = n1 * n2; break;
                case '/': res = n1 / n2; break;
                case '^': res = pow(n1, n2); break;
            }
            
            push(&st, res);
            sprintf(symbol, "%c", *p);
            sprintf(eval_str, "%.1f %c %.1f = %.1f", n1, *p, n2, res);
            printf("%-10s | %-25s | ", symbol, eval_str);
            p++;
        }
        
        printStack(st);
        printf("\n");
    }

    printf("----------------------------------------------------------------------\n");
    printf("Final Result: %.2f\n", pop(&st));

    return 0;
}

