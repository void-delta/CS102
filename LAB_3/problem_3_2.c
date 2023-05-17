/* Write a C program to demonstrate the various operations of the circular queue (both
implementations discussed in the class) such as enque, deque and display. The program should be
menu driven. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int fron = -1;
int rear = -1;
int counter = 0;

void insert(int n)
{
    if((fron == 0 && rear == MAX -1) || (fron == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if(fron == -1)
    {
        fron = 0;
        rear = 0;
    }
    else
    {
        if(rear = MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    queue[rear] = n;
}

int delete()
{
    if(fron == -1)
    {
        printf("Queue Overflow\n");
        exit(101);
    }
    int c = queue[fron];
    if(fron == rear)
    {
        fron = -1;
        rear = -1;
    }
    else
    {
        if(fron = MAX - 1)
            fron = 0;
        else
            fron = fron + 1;
    }
    return c;
}

void display()
{
    int fi = fron, ri = rear;
    if(fron == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue Elements:\t");
    if(fi <= ri)
    {
        while(fi <= ri)
        {
            printf("%d ", queue[fi]);
            fi = fi + 1;
        }
    }
    else
    {
        while(fi <= MAX - 1)
        {
            printf("%d ", queue[fi]);
            fi = fi + 1;
        }
        fi = 0;
        while(fi <= ri)
        {
            printf("%d ", queue[fi]);
            fi = fi + 1;
        }
    }
    printf("\n\n");
}

int main()
{
    while(1)
    {
        printf("1)Enqueue 2)Dequeue 3)Display 4)Exit\t");
        int n;
        scanf("%d", &n);

        switch(n)
        {
            case 1:
            printf("Enter the Number:\t");
            int x;
            scanf("%d", &x);
            insert(x);
            break;

            case 2:
            x = delete();
            printf("%d Dequeued\n");
            break;

            case 3:
            display();
            break;

            case 4:
            return 0;

            default:
            printf("INVALID INPUT\n");
            break;
        }
    }
    return 0;
}   