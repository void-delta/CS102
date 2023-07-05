#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void display(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

Node *swap(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node *adj_swap(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL && ptr->next != NULL)
    {
        // swap(ptr, ptr->next);
        int temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;

        ptr = ptr->next->next;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Original Linked List: \n");
    display(head);

    // head = swapAdjacentNodes(head);
    head = adj_swap(head);

    printf("Swapping Nodes......\n");
    printf("Modified Linked List: \n");
    display(head);

    return 0;
}