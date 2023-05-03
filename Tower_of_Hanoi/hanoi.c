/* Tower of Hanoi */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack{
    int arr[MAX];
    int top;
} stack;

void push(stack *st, int n)
{
    if(st->top != MAX - 1)
    {
        st->top += 1;
        st->arr[st->top] = n;
        return;
    }
    printf("Stack overflow 1\n");
    exit(101);
}

int pop(stack *st)
{
    if(st->top != -1)
    {
        int c = st->arr[st->top];
        st->top -= 1;
        return c;
    }
    printf("Stack Underflow 1\n");
    exit(102);
}

void display(stack *st);

void hanoi(int n, stack *st1, stack *st2, stack *st3)
{
    if(n == 1)
    {
        push(st2, pop(st1));
        /* display(st1);
        display(st2);
        display(st3);
        printf("\n"); */
        return;
    }
    else
    {
        hanoi(n-1, st1, st3, st2);
        hanoi(1, st1, st2, st3);
        hanoi(n-1, st3, st2, st1);
    }
}

void display(stack *st)
{
    if(st->top != -1)
    {
        for(int i = 0; i <= st->top; i++)
        {
            printf("%d ", st->arr[i]);
        }
        printf("\n");
        return;
    }
    else
        printf("Stack Empty\n");
        return;

}

int main()
{
    printf("Number of Disks in the Tower\t");
    int n;
    scanf("%d", &n);
    stack st1, st2, st3;
    st1.top = -1;
    st2.top = -1;
    st3.top = -1;

    for(int i = n; i > 0; i--)
    {
        // printf("%d ", i);
        push(&st1, i);
    }
    display(&st1);
    display(&st2);
    display(&st3);

    printf("\nsolving in Vietnam\n\n");

    hanoi(n, &st1, &st2, &st3);

    display(&st1);
    display(&st2);
    display(&st3);
    
    return 0;
}