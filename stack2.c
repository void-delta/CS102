#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct stack {
    char arr[MAX];
    int top;
};

int isEmpty(struct stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    else return 0;
}

int isFull(struct stack st)
{
    if(st.top == MAX-1)
    {
        return 1;
    }
    else return 0;
}

char peek(struct stack st)
{
    if(!isEmpty(st))
    {
        return st.arr[st.top];
    }
    else 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
}

void push(char c, struct stack *st)
{
    if(!isFull(*st))
    {
        st->top = st->top + 1;
        st->arr[st->top] = c;
    }
    else 
    {
        printf("Stack Overflow\n");
        exit(2);
    }
}

char pop(struct stack *st)
{
    char c;
    if(!isEmpty(*st))
    {
        c = st->arr[st->top];
        st->top--;
        return c;
    }
    else
    {
        printf("Stack Underflow\n");
        exit(3);
    }
}

int main()
{
    struct stack name = { .top = -1 };

    while(1) 
    {
        printf("1)Push 2)POP 3)Peek 4)Exit\t");
        int x;
        scanf("%d", &x);

        switch(x)
        {
            case 1:
                printf("Enter the Character to be added\t");
                char c;
                scanf(" %c", &c);
                push(c, &name);
                printf("Pushed\n");
                break;

            case 2:
                printf("POPPED %c\n", pop(&name));
                break;

            case 3:
                printf("%c is at the top of the stack\n", peek(name));
                break;

            case 4:
                goto delta;

            default: 
                printf("Invalid Input\n");
                break;
        }
    }

    delta: 
    return 0;
}
