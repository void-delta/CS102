#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* You are given the Instagram post caption of a popular influencer which contains hashtags. 
In one operation, you can: 
● Choose a hash in the caption. 
● Remove the closest non-hash character to its left, as well as remove the hash symbol itself. 
Print the caption after all hashes have been removed. */

#define MAX 35

int stack[MAX];
int top = -1;

char pop()
{
    if(top != -1)
    {
        char c = stack[top];
        top = top - 1;
        return c;
    }
    else 
        printf("Stack Underflow\n");
    exit(101);
}

void push(char c)
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

void display()
{
    if(top != -1)
    {
        for(int i = 0; i <= top; i++)
        {
            printf("%c", stack[i]);
        }
        printf("\n");
        return;
    }
    else
        printf("Stack Underflow\n");
    return;
}

int main()
{
    printf("Enter the STring with the HASH\n\n");
    char arr[MAX];
    scanf("%s", arr);
    int len = strlen(arr);
    char c;

    for(int i = 0; i < len; i++)
    {
        if(isalnum(arr[i]))
        {
            push(arr[i]);
        }
        else if(arr[i] == '#')
        {
            c = pop();
        }
        else 
            continue;
    }
    printf("The actual string is\t");
    display();
    return 0;
}
