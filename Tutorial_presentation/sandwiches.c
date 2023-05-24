/* The school cafeteria offers circular and square sandwiches at lunch break, 
referred to by numbers 0 and 1 respectively. All students stand in a queue. 
Each student either prefers square or circular sandwiches.
The number of sandwiches in the cafeteria is equal to the number of students. 
The sandwiches are placed in a stack. At each step:

    >If the student at the front of the queue prefers the sandwich on the top of the stack, 
     they will take it and leave the queue.
    >Otherwise, they will leave it and go to the queue's end.
    >This continues until none of the queue students want to take the 
     top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the 
type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the 
preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). 
Return the number of students that are unable to eat. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int sandwich[MAX];
int top = -1;
int student[MAX];
int rear = -1;
int fron = 0;

void push(int i)
{
    if(top != MAX - 1)
    {
        top = top + 1;
        sandwich[top] = i;
        //printf("Push Confirmed\n");
        return;
    }
    else 
        printf("Stack Overflow\n");
        exit(101);
}

int pop()
{
    if(top != -1)
    {
        int a = sandwich[top];
        top = top - 1;
        return a;
    }
        
    else
        printf("Stack Undeflow\n");
        exit(102);
}

void enqueue(int n)
{
    if(rear != MAX - 1)
    {
        rear = rear + 1;
        student[rear] = n;
        //printf("Enqueued %d\n", student[rear]);
    }
    else
        printf("Queue Overflow\n");
    return;
}

int dequeue()
{
    if(fron <= rear)
    {
        int c = student[fron];
        fron = fron + 1;
        //printf("Dequeued %d\n", c);
        return c;
    }
    else
        printf("Queue Undeflow\n");
    exit(103);
}

int peeksand()
{
    if(top != -1)
        return sandwich[top];
    else    
        printf("Stack Underflow\n");
        exit(104);
}

int current_student()
{
    if(fron <= rear)
    {
        return student[fron];
    }
    else
        printf("Queue Undeflow\n");
    exit(105);
}

int main()
{
    printf("Enter the Number of Students\t");
    int n_stu, n, count = 0;
    scanf("%d", &n_stu);
    printf("Enter the preferences of the Students\n");

    for(int i = 0; i < n_stu; i++)
    {
        scanf("%d", &n);
        enqueue(n);
    }

    printf("Enter the Sandwiches made in the Cafeteria\n");

    for(int i = 0; i < n_stu; i++)
    {
        scanf("%d", &n);
        push(n);
    }

    printf("Calculating.........\n");
    printf("STudents\tSandwiches\n");

    int t1, t2;
    for(int i = 0; i < n_stu; i++)
    {
        t1 = peeksand();
        t2 = current_student();
        printf("%d\t\t %d\n", t2, t1);
        if(t1 == t2)
        {
            count = count + 1;
            pop();
            dequeue();
        }
        else
        {
            dequeue();
        }
    }
    printf("STUDENTS who get a sandich of their liking are %d\n", count);
    return 0;
}