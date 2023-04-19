#include <stdio.h>
#define maxsize 10

int top=-1;
int stack[maxsize];

int isFull()
{
    if (top == maxsize - 1)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int isEmpty()
{
    if ( top == -1)
    {
        return 0;
    }
    else {
        return 1;
    }
}

void peek()
{
    int a = isEmpty();
    if (a == 1){
        printf("%d\n", stack[top]);
    }
    else{
        printf("Stack Empty\n");
    }
    
}

void push(int data)
{   
    int a = isFull();
    if(a==1)
    {
        top = top + 1;
        stack[top] = data;
        printf("Push confirmed\n");
    }
    else {
        printf("Stack is Full.\n");
    }
}

void pop()
{
    int data, a;
    a = isEmpty();
    if (a == 1)
    {
        data = stack[top];
        top = top - 1;
        printf("%d popped out\n", data);
    }
    else {
        printf("Stack is Empty\n");
    }
}

int main()
{
    label: printf("ENTER 1)Pushing 2)Popping 3)Peeking 4)Exit\t");
    int x;
    scanf("%d", &x);

    switch(x)
    {
        case 1: 
        {
            printf("Enter the data to enter\n");
            int d;
            scanf("%d", &d);
            push(d);
            goto label;
        }

        case 2:
        {
            printf("Please confirm pop\nType 1\t");
            int a;
            scanf("%d", &a);
            if (a == 1){
                pop();
            }
            goto label;
        }

        case 3:
        {
            peek();
            goto label;
        }

        case 4: return 0;
        
        default: {
            printf("Invalid Input\n");
            goto label;
        }
    }
    return 0;
}