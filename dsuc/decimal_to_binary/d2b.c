#include <stdio.h>
#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;
}

void decimalToBinary(int decimal) {
    struct Stack s;
    initialize(&s);
    
    // Push remainders onto stack
    while (decimal > 0) {
        push(&s, decimal % 2);
        decimal /= 2;
    }
    
    // Pop and print binary digits
    printf("Binary number: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    decimalToBinary(decimal);
    
    return 0;
}