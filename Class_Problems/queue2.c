/* Implementing QUEUE using structures */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 25

struct queue{
    int kyu[MAX];
    int fron;
    int rear;
};

void enqueue(int n, struct queue *q)
{
    if(q->rear != MAX - 1)
    {
        q->rear = q->rear + 1;
        q->kyu[q->rear] = n;
        return;
    }
    else
        printf("Queue Overflow\n");
    return;
}

int dequeue(struct queue *q)
{
    if(q->fron <= q->rear)
    {
        int c = q->kyu[q->fron];
        q->fron = q->fron + 1;
        return c;
    }
    else
        printf("Queue Underflow\n");
    exit(101);
}

void display(struct queue *q)
{
    if(q->fron <= q->rear)
    {
        for(int i = q->fron; i <= q->rear; i++)
        {
            printf(" %d ", q->kyu[i]);
        }
        printf("\n");
        return;
    }
    else
        printf("Queue Underflow\n");
    return;
}

int peek(struct queue *q)
{
    if(q->fron <= q->rear)
    {
        return q->kyu[q->rear];
    }
    else
        printf("Queue Undeflow\n");
    exit(102);
}

int main()
{
    struct queue qu;
    qu.fron = 0;
    qu.rear = -1;

    while(1)
    {
        printf("1)Enqueue 2)Dequeue 3)Display 4)Peek 5)Quit\t");
        int x;
        scanf("%d", &x);

        if(x == 1)
        {
            printf("Enter the Number to be Enqueued\t");
            int n;
            scanf("%d", &n);
            enqueue(n, &qu);
        }
        else if(x == 2)
        {
            printf("%d dequeued\n", dequeue(&qu));
        }
        else if(x == 3)
        {
            printf("The queue is \n\n");
            display(&qu);
        }
        else if(x == 4)
        {
            printf("The Element is\t%d\n", peek(&qu));
        }
        else if(x == 5)
        {
            return 0;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
}