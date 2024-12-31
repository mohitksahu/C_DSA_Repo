#include <stdio.h>
#include <string.h>
#define MAX 100

struct Stack {
    char items[MAX];
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

void push(struct Stack *s, char value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    }
}

char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

void reverseString(char *str) {
    struct Stack s;
    initialize(&s);
    
    // Push characters to stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }
    
    // Pop characters to reverse the string
    int i = 0;
    while (!isEmpty(&s)) {
        str[i++] = pop(&s);
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);
    
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    
    return 0;
}