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

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;
}

int reverseNumber(int num) {
    struct Stack s;
    initialize(&s);
    
    // Push digits to stack
    while (num > 0) {
        push(&s, num % 10);
        num /= 10;
    }
    
    // Pop digits and reconstruct number
    int reversed = 0;
    int multiplier = 1;
    while (!isEmpty(&s)) {
        reversed = reversed * 10 + pop(&s);
    }
    
    return reversed;
}

int main() {
    int number;
    printf("Enter a number to reverse: ");
    scanf("%d", &number);
    
    int reversed = reverseNumber(number);
    printf("Reversed number: %d\n", reversed);
    
    return 0;
}