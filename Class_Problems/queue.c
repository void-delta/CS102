/* Logic for enqueue and dequeue */
#include <stdio.h>
#include <stdlib.h>

#define MAX 25

typedef struct queue{
    int arr[MAX];
    int rear;
    int front;
} queue;

void enqueue(int n, queue *q)
{
    q->arr[q->rear] = n;
    return;
}

int dequeue(queue *q)
{
    int c = q->arr[q->front];
    
}