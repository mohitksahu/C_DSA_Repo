#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    char items[MAX];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, char c) {
    s->items[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (s->top == -1) return '\0';
    return s->items[(s->top)--];
}

char peek(struct Stack *s) {
    if (s->top == -1) return '\0';
    return s->items[s->top];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char *infix) {
    struct Stack s;
    initialize(&s);
    
    int i, j;
    int len = strlen(infix);
    char postfix[MAX];
    j = 0;
    
    for (i = 0; i < len; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        else {
            while (s.top != -1 && precedence(infix[i]) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix);
    return 0;
}