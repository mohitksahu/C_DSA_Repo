#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initialize(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    display(&s);
    
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    
    display(&s);
    
    return 0;
}