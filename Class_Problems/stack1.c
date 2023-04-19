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