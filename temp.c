#include<stdio.h>
int stk[10];
int top = -1;
void push(int val)
{
    stk[++top] = val;
}
int pop()
{
    return stk[top--];
}
int main()
{
    int n,i, a[10], val;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the values\n");
    for(i=0; i<n; i++)
    {
    scanf("%d", &a[i]);
    push(a[i]);
    }
    for(i=0; i<n; i++)
    {
        val = pop();
        a[i]= val;
    }
    printf("Reversed number is :");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}