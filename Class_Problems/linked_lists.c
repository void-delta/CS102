/* Linked Lists Deployment */

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    int info;
};

struct node *start = NULL;

void insert(int data)
{
    printf("Insert\n1)At Start 2)In Middle 3)At End\t");
    int n;
    scanf("%d", &n);
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    switch(n)
    {
        case 1:{
            new_node->next = start;
            start = new_node;
            new_node->info = data;
            break;
        }
        case 2:{
            printf("Enter the Position to enter the Node at\t");
            int x, i = 1;
            scanf("%d", &x);
            new_node->info = data;
            temp = start;
            while(i < x - 1){
                temp = temp->next;
                i = i + 1;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        case 3:{
            new_node->info = data;
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = NULL;
            break;
        }
        default:
            printf("Request Could Not be Carried Out\n");
    }
    return;
}

void delete()
{
    printf("Delete at\n1)At Front 2)At End 3)In Middle\t");
    int n;
    scanf("%d", &n);
    if(start == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    struct node *temp, *prev;
    switch(n)
    {
        case 1:
        {
            temp = start;
            start = temp->next;
            free(temp);
            break;
        }
        case 2:
        {
            temp = start;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            free(temp);
            prev->next = NULL;
            break;
        }
        case 3:
        {
            int i = 1, x;
            printf("Enter the Position\t");
            scanf("%d", &x);
            struct node *pos;
            temp = start;
            while(i < x - 1){
                temp = temp->next;
                i = i + 1;
            }
            pos = temp->next;
            temp->next = pos->next;
            free(pos); 
            break;
        }
    }
    return;
}

void traverse()
{
    struct node *temp;
    int count=0;
    // check if the list is empty
    if (start == NULL)
        printf("\nList is empty\n");
 
    // if not, print the contents of the LL
    else {
        temp = start;
        while (temp != NULL) {
            printf("Data_%d_node = %d\n",count, temp->info);
            temp = temp->next;
            count++;
        }
    }
    return;
}

int main()
{
    while(1)
    {
        printf("1)Insert 2)Delete 3)Display 4)Exit\t");
        int n;
        scanf("%d", &n);

        switch(n)
        {
            case 1:
            {
                printf("Enter the digit to be entered\t");
                int x;
                scanf("%d", &x);
                insert(x);
                break;
            }
            case 2:
            {
                delete();
                break;
            }
            case 3:
            {
                traverse();
                break;
            }
            case 4:
            {
                return 0;
            }
        }
    }
    
}