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
        return 1;
    else 
        return 0;
}

int isEmpty()
{
    if(tpr.top == -1)
        return 1;
    else
        return 0;
}

void push(char c, struct arr *tpr)
{
    if(!isFull())
    {
        tpr->top = tpr->top + 1;
        tpr->name[tpr->top] = c;
        return;
    }
    else
    {
        printf("Stack Overflow\n");
        return;
    }
}

void display(int len, struct arr *ch)
{
    for(int i = tpr.top; i >= 0; i = i - 1)
    {
        printf("%c", ch->name[i]);
    }
    return;
}

int checkp(int len, char ch[], struct arr *tpr)
{
    for(int i = 0; i < len; i++)
    {
        push(ch[i], tpr);
        // printf("%d", i); to check the functioning
    }

    int a = 0;
    for(int i = 0, t = tpr->top; i < len || t > -1; i++, t--)
    {
        if(ch[i] == tpr->name[t])
            continue;
        else
            a = 1;
    }

    if(a == 0)
       return 0;
    else
       return 1;
    
}

void reverse(int len, char ch[], struct arr *tpr)
{
    for(int i = 0; i < len; i++)
    {
        push(ch[i], tpr);
        // printf("%d", i); to check the functioning
    }
    display(len, tpr);
    return;
}

int main()
{
    tpr.top = -1;
    char str[MAX];
    printf("Enter the String\t");
    scanf("%s", str);
    int len = strlen(str);

    printf("1) Reverse  2) Check for Palindrome\n\t\t");
    int x;
    scanf("%d", &x);

    if(x == 1)
        reverse(len, str, &tpr);

    else if(x == 2)
    {
        int a = checkp(len, str, &tpr);

        if(a == 0)
            printf("String is Palindrome\n");
        else
            printf("String is not Palindrome\n");
    }
    return 0;
}