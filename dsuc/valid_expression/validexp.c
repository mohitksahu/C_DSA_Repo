#include <stdio.h>
#include <stdlib.h>

int stk[10];
int top=-1;

void push(int val) {
    stk[++top]=val;
}

int pop() {
    return stk[top--];
}

int main() {
    char exp[100], temp;
    int i, flag=1;

    printf("Enter your expression: ");
    gets(exp);

    for (i=0; exp[i]!='\0'; i++) {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            push(exp[i]);
        }

        if (exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if (top == -1) {
                flag=0;
                break;
            } else{
                temp=pop();
                if ((exp[i]==')' && temp!='(') || (exp[i]=='}' && temp!='{')
                || (exp[i]==']' && temp!='[')) {
                    flag =0;
                    break;
                }
            }
        }
    }
    if (top>=0) {
        flag=0;
    }

    if (flag==1) {
        printf("expression is valid\n");
    }
    else {
        printf("Expression is invalid\n");
    }
}
