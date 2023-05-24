/* You are keeping the scores for a baseball game with strange rules. 
At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is 
the ith operation you must apply to the record and is one of the following:

An integer x: Record a new score of x.
'+': Record a new score that is the sum of the previous two scores.
'D': Record a new score that is the double of the previous score.
'C': Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 35

int stack[MAX];
int top = -1;

int pop()
{
    if(top != -1)
    {
        int c = stack[top];
        top = top - 1;
        return c;
    }
    else 
        printf("Stack Underflow\n");
    exit(101);
}

void push(int c)
{
    if(top != MAX - 1)
    {
        top = top + 1;
        stack[top] = c;
        return;
    }
    else 
        printf("Stack Overflow\n");
    return;
}

int peek()
{
    if(top != -1)
        return stack[top];
    else    
        printf("Stack Underflow\n");
        exit(103);
}

int sum()
{
    if(top != -1){
        int sum = 0;
        for(int i = top; i > -1; i--)
            sum = sum + stack[i];
        return sum;
    }
    else 
        printf("ERROR IN SUM\n");
        exit(104);
}

int main()
{
    while(1)
    {
        printf("ENTER 1)Add Number");
        printf("+)Sum of last two No. D)Double last No.");
        printf("C)Cancel the last element 2)Done\n");
        char x;
        scanf(" %c", &x);

        if(x == '1')
        {
            int n;
            printf("Enter the Number\t");
            scanf("%d", &n);
            push(n);
        }
        else if(x == '+')
        {
            int n = pop();
            int m = peek();
            push(n);
            push(m + n);
        }
        else if(x == 'D')
            push(2*peek());
        else if(x == 'C')
            top = top - 1;
        else if(x == '2')
            break;
    }
    printf("SCORE is %d\n", sum());
    return 0;
}