/* Reverse a number and store it another variable using stacks */

 #include <stdio.h>
 #include <stdlib.h>
 
 #define MAX 10

 struct stack{
    arr[MAX];
    top;
 };

 int isEmpty(struct stack *st)
 {
    if(st->top == -1)
        return 1;
    else
        return 0;
 }

 int isFull(struct stack *st)
 {
    if(st->top == MAX - 1)
        return 1;
    else 
        return 0;
 }

 int pop(struct stack *st)
 {
    if(!isEmpty(&st))
    {
        int c = st->arr[st->top];
        st->top = st->top - 1;
        return c;
    }
    else 
        printf("Stack Underflow\nTerminating Program\n");
    exit(101);
 }