#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct stackChar
{
    char arr[MAX];
    int top;
};

struct stackInt
{
    int arr[MAX];
    int top;
};

int isEmptyI(struct stackInt st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct stackChar st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(struct stackChar st)
{
    if (st.top == MAX - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isFullI(struct stackInt st)
{
    if (st.top == MAX - 1)
    {
        return 1;
    }
    else
        return 0;
}

char peek(struct stackChar st)
{
    if (!isEmpty(st))
    {
        return st.arr[st.top];
    }
    else
    {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int peekI(struct stackInt st)
{
    if (!isEmptyI(st))
    {
        return st.arr[st.top];
    }
    else
    {
        printf("Stack Underflow");
        exit(101);
    }
}

void push(char c, struct stackChar *st)
{
    if (!isFull(*st))
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

void pushI(int c, struct stackInt *st)
{
    if (!isFullI(*st))
    {
        st->top = st->top + 1;
        st->arr[st->top] = c;
    }
    else
    {
        printf("Stack Overflow\n");
        exit(102);
    }
}

char pop(struct stackChar *st)
{
    char c;
    if (!isEmpty(*st))
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

int popI(struct stackInt *st)
{
    char c;
    if (!isEmptyI(*st))
    {
        c = st->arr[st->top];
        st->top--;
        return c;
    }
    else
    {
        printf("Stack Underflow I\n");
        exit(3);
    }
}

int main()
{
    char str[MAX];
    printf("Enter the expression\n");
    scanf("%s", str);

    int precedence[256];
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['('] = 0;
    precedence[')'] = 0;

    // step 1
    struct stackInt operand;
    struct stackChar operator;
    operand.top = -1;
    operator.top = - 1;

    // step 2
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]) == 1)
        {
            pushI(str[i] - '0', &operand);
        }

        // step 3
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (isEmpty(operator))
            {
                push(str[i], &operator);
            }
            else
            {
                if (precedence[str[i]] >= precedence[peek(operator)])
                {
                    push(str[i], &operator);
                    printf("Pushed: %c\n", str[i]);
                }
                else
                {
                    while (!(precedence[str[i]] >= precedence[peek(operator)]))
                    {
                        char o = pop(&operator);
                        int a = popI(&operand);
                        int b = popI(&operand);

                        // int aVal = (int) a - (int) '0';
                        // int bVb1 = (int) b - (int) '0';
                        switch (o)
                        {
                        case '+':
                            pushI(a + b, &operand);
                            break;

                        case '-':
                            pushI(a - b, &operand);
                            break;

                        case '*':
                            pushI(a * b, &operand);
                            break;

                        case '/':
                            pushI(a / b, &operand);
                            break;
                        }
                    }
                    push(str[i], &operator);
                }
            }
        }
        // step 4
        else if (str[i] == '(')
        {
            push(str[i], &operator);
        }
        // step 5
        else if (str[i] == ')')
        {
            char o;
            while(1) {
                o = pop(&operator);

                if(o == '(') break;

                int a = popI(&operand);
                int b = popI(&operand);

                // int aVal = (int) a - (int) '0';
                // int bVb1 = (int) b - (int) '0';
                switch (o)
                {
                case '+':
                    pushI(a + b, &operand);
                    break;

                case '-':
                    pushI(a - b, &operand);
                    break;

                case '*':
                    pushI(a * b, &operand);
                    break;

                case '/':
                    pushI(a / b, &operand);
                    break;
                }
            }
        }
    }

    printf("Result: %d", popI(&operand));
    // printf(": ")
}
