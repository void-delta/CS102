/* Polynomial Deployment in Linked List */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;

void insert_new(struct node *start, int co, int ex)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coeff = co;
    new_node->exp = ex;
    struct node *q = start;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = new_node;
    new_node->next = NULL;
    return;
}

void display(struct node *q)
{
    struct node *a = q;
    while(a != NULL){
        printf("%dx^%d + ", a->coeff, a->exp);
        a = a->next;
    }
    printf("\n");
    return;
}

void add(struct node *a1, struct node *a2, struct node *b)
{
    struct node *q1, *q2;
    q1 = a1;
    q2 = a2;
    
    while(q1 != NULL && q2 != NULL)
    {
        if(q1->exp == q2->exp)
        {
            int deb = q1->coeff + q2->coeff;
            int po = q1->exp;
            insert_new(b, deb, po);
            q1 = q1->next;
            q2 = q2->next;
        }
        else if(q1->exp > q2->exp)
        {
            insert_new(b, q1->coeff, q1->exp);
            q1 = q1->next;
        }
        else
        {
            insert_new(b, q2->coeff, q2->exp);
            q2 = q2->next;
        }
    }
    printf("The Summation is\n");
    display(b);
    return;
}

int main()
{
    printf("Enter the Degree of Polynomial A\t");
    int n;
    scanf("%d", &n);

    for(int i = n; i > -1; i--)
    {
        printf("Enter the Coefficient of %d degree\t", i);
        int a;
        scanf("%d", &a);
        insert_new(&start1, a, i);
    }

    printf("Enter the Degree of Polynomial B\t");
    scanf("%d", &n);

    for(int i = n; i > -1; i--)
    {
        printf("Enter the Coefficient of %d degree\t", i);
        int a;
        scanf("%d", &a);
        insert_new(&start2, a, i);
    }
    add(&start1, &start2, &start3);
    return 0;
}