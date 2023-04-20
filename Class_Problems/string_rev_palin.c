#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

struct arr{
    char name[MAX];
    int top;
}tpr;

int isFull()
{
    if(tpr.top == MAX - 1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int isEmpty()
{
    if(tpr.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    tpr.top = -1;
    char str[MAX];
    printf("Enter the String\t");
    scanf("%s", str);

    printf("1) Reverse\n2) Check for Palindrome\n\t\t");
    int x;
    scanf("%d", &x);

    if(x == 1)
    {
        reverse(str, tpr);
    }

    else if(x == 2)
    {
        int a = checkp(str, tpr);

        if(a == 1)
        {
            printf("String is Palindrome\n");
        }
        else
        {
            printf("String is not Palindrome\n");
        }
    }
    return 0;
}

void push(char c, struct arr tpr)
{
    if(!isFull())
    {
        tpr.top = tpr.top + 1;
        tpr.name[tpr.top] = c;
        return;
    }
    else
    {
        printf("Stack Overflow\n");
        return;
    }
}

void display(struct arr ch)
{
    for(int i = tpr.top; i != -1; i = i - 1)
    {
        printf("%c", ch.name[i]);
    }
    return;
}

int checkp(char *ch[], struct arr tpr)
{
    for(int i = 0; tpr.top != -1; i++)
    {
        push(ch[i], tpr);
    }

    for(int i = 0, t = tpr.top; i < tpr.top; i++, t--)
    {
        int a = 0;
        if(ch[i] == tpr.name[t])
        {
            continue;
        }
        else
        {
            a = 1;
        }

        if(a == 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void reverse(char *ch[], struct arr tpr)
{
    for(int i = 0; tpr.top != -1; i++)
    {
        push(ch[i], tpr);
    }
    display(tpr);
}