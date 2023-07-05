#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *insert(Node *head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = new_node;
        new_node->prev = ptr;
    }

    return head;
}

void swap(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node *sortAscending(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    int swapped;
    Node *ptr;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);

    return head;
}

Node *sortDescending(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    int swapped;
    Node *ptr;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->data < ptr->next->data)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);

    return head;
}

int main()
{
    Node *head = NULL;
    int choice;
    int data;

    while (1)
    {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Sort in ascending order\n");
        printf("3. Sort in descending order\n");
        printf("4. Display\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            head = insert(head, data);
            break;

        case 2:
            head = sortAscending(head);
            printf("List sorted in ascending order\n");
            display(head);
            break;

        case 3:
            head = sortDescending(head);
            printf("List sorted in descending order\n");
            display(head);
            break;

        case 4:
            printf("Linked List: \n");
            display(head);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}