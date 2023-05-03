/* Logic for enqueue and dequeue */
#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int queue[MAX];
int fron = 0;
int rear = -1;

void enqueue(int n)
{
    if(rear != MAX - 1)
    {
        rear = rear + 1;
        queue[rear] = n;
        printf("Enqueued\n");
    }
    else
        printf("Queue Overflow\n");
    return;
}

int dequeue()
{
    if(fron <= rear)
    {
        int c = queue[fron];
        fron = fron + 1;
        printf("Dequeued\n");
        return c;
    }
    else
        printf("Queue Undeflow\n");
    exit(101);
}

void display()
{
    if(fron <= rear)
    {
        for(int i = fron; i <= rear; i++)
        {
            printf(" %d ", queue[i]);
        }
        printf("\n");
        return;
    }
    else
        printf("Queue Underflow\n");
    exit(102);
}

int main()
{
    while(1)
    {
        printf("1)Enqueue 2)Dequeue 3)Display 4)Quit\t");
        int x;
        scanf("%d", &x);

        if(x == 1)
        {
            printf("Enter the Number to be Enqueued\t");
            int n;
            scanf("%d", &n);
            enqueue(n);
        }
        else if(x == 2)
        {
            printf("%d dequeued\n", dequeue());
        }
        else if(x == 3)
        {
            printf("The queue is \n\n");
            display();
        }
        else if(x == 4)
        {
            return 0;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
    return 0;
}