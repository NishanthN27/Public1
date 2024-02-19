#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void push(int s[MAX], int *top, int elem)
{
    if (*top==MAX-1) 
    {
        printf("Overflow\n");
        return;
    }
    (*top)++;
    s[*top]=elem;
}

int pop(int s[MAX],int *top) 
{
    if (*top==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    int elem=s[*top];
    (*top)--;
    return elem;
}

void display(int s[MAX],int top)
{
    if (top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:");
    for (int i=0;i<=top;i++)
        printf("%d\t",s[i]);
    printf("\n");
}

void reverse(int s[MAX],int *top) 
{
    if ((*top)==-1) 
    {
        printf("Stack is empty\n");
        return;
    }
    int size=(*top)+1;
    int temp[size];
    for (int i=0;i<size;i++)
        temp[i]=pop(s,top);
    for (int i=0;i<size;i++)
        push(s,top,temp[i]);
}

int main() 
{
    int stack[MAX],top=-1,ch,elem;
    for(;;) 
    {
        printf("\nEnter\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Reverse\n");
        printf("5.Exit\n");
        scanf("%d",&ch);
        switch (ch) 
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&elem);
                push(stack,&top,elem);
                break;
            case 2:
                elem=pop(stack,&top);
                if (elem != -1)
                    printf("Popped element:%d\n",elem);
                break;
            case 3:
                display(stack,top);
                break;
            case 4:
                reverse(stack,&top);
                printf("Stack Reversed\n");
                break;
            default:
                printf("Exiting\n");
                exit(0);
        }
    }
}
