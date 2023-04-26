/* Reverse a number and store it another variable using stacks */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define MAX 10

 struct stack{
    int arr[MAX];
    int top;
 }unit;

 int isEmpty(struct stack unit)
 {
    if(unit.top == -1)
        return 0;
    else
        return 1;
 }

 int isFull(struct stack unit)
 {
    if(unit.top == MAX - 1)
        return 0;
    else 
        return 1;
 }

 int pop(struct stack *unit)
 {
    if(isEmpty(*unit))
    {
        int c = unit->arr[unit->top];
        unit->top = unit->top - 1;
        return c;
    }
    else
        printf("Stack Underflow 1\nTerminating Program\n");
    exit(101);
 }

 void push(struct stack *unit, int a)
 {
    if(isFull(*unit))
    {
        unit->top = unit->top + 1;
        unit->arr[unit->top] = a;
        return;
    }
    else
        printf("Stack Overflow 2\nTerminating Program\n");
    exit(102);
 }

 int main()
 {
    unit.top = -1;

    printf("%d\n", unit.top);
    printf("Enter the number\t");
    int pt;
    scanf("%d", &pt);
    
    int x = 1;
    int result = 0;
    while(pt != 0)
    {
        push(&unit, pt%10);
        pt = pt/10;
    }

    while(unit.top != -1)
    {
        result += pop(&unit)*x;
        x = x*10;
    }
    printf("Reversed number is %d\n", result);
    
    /*for(; pt != 0 ; pt/10)
    {
        x = x + 1;
        int b = pt%10;
        push(&unit, &b);
    }

    int sum = 0;
    int a = 1;

    for(int i = 0; i < x; i++, a*10)
    {
        sum = sum + pop(&unit)*a;
    }
    printf("Reversed Integer\t%d\n", sum);*/
 }