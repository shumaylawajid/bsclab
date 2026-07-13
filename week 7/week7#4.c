#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) { 
    if (top < MAX - 1) stack[++top] = x; 
}

char pop() { 
    return (top == -1) ? -1 : stack[top--]; 
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

/* Shows the trace exactly like your image: starting with one '(' */
void printStack() {
    int i;
     
    for (i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
}

int main() {
    char exp[MAX], postfix[MAX * 2], *e, x;
    int pIdx = 0; 
    size_t len;

    printf("Enter infix expression: ");
    if (fgets(exp, MAX - 2, stdin) == NULL) return 0;

    /* Clean up the newline from fgets */
    len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') exp[len - 1] = '\0';

    /* INITIALIZATION FOR THE "BOOK METHOD" */
    top = -1; 
    push('(');        /* Pre-push the initial bracket */
    strcat(exp, ")"); /* Add the closing 'cleanup' bracket */

    printf("\n%-10s | %-15s | %-20s\n", "Symbol", "Stack", "Postfix Status");
    printf("--------------------------------------------------------------\n");

    for (e = exp; *e != '\0'; e++) {
        if (isspace(*e)) continue;

        if (isalnum(*e)) {
            /* Add comma if needed */
            if (pIdx > 0 && postfix[pIdx-1] != ',') postfix[pIdx++] = ',';
            postfix[pIdx++] = *e;
            postfix[pIdx] = '\0';
        } 
        else if (*e == '(') {
            push(*e);
        } 
        else if (*e == ')') {
            /* Pop until the matching '(' is found */
            while (top != -1 && (x = pop()) != '(') {
                if (pIdx > 0) postfix[pIdx++] = ',';
                postfix[pIdx++] = x;
                postfix[pIdx] = '\0';
            }
        } 
        else {
            /* Operator Logic: Pop higher/equal priority */
            /* Note: *e != '^' handles right-associativity */
            while (top != -1 && priority(stack[top]) >= priority(*e) && *e != '^') {
                char temp = pop();
                if (pIdx > 0) postfix[pIdx++] = ',';
                postfix[pIdx++] = temp;
                postfix[pIdx] = '\0';
            }
            push(*e);
        }

        /* TRACE OUTPUT */
        printf("%-10c | ", *e);
        printStack();
        /* Aligning the postfix column */
        printf("\t\t | %-20s\n", postfix);
    }

    printf("--------------------------------------------------------------\n");
    printf("Final Postfix Result: %s\n", postfix);

    return 0;
}

