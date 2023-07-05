#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Tree;

Tree *insertNode(Tree *root, int data)
{

    Tree *new_node = (Tree *)malloc(sizeof(Tree));
    if (root == NULL)
    {
        new_node->left = NULL;
        new_node->data = data;
        new_node->right = NULL;

        return new_node;
    }

    if (new_node->data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (new_node->data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Tree *search(Tree *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    else if (data > root->data)
    {
        return search(root->right, data);
    }
}

void inorder(Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

Tree *deleteNode(Tree *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->right == NULL)
        {
            Tree *ptr = root->left;
            free(root);
            return ptr;
        }
        else if (root->left == NULL)
        {
            Tree *ptr = root->right;
            free(root);
            return ptr;
        }

        Tree *minValue = root->right;
        while (minValue->left != NULL)
        {
            minValue = minValue->left;
        }

        root->data = minValue->data;
        root->right = deleteNode(root->right, minValue->data);
    }

    return root;
}

int main()
{
    Tree *root = NULL;
    Tree *s = NULL;
    int count = 0;
    int choice, data, key, deletekey;
    while (1)
    {
        printf("Binary Tree Program\n\n");
        printf("\n1)Insertion\n2)Searching\n3)Deletion\n4)Display\n5)Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted into Binary Tree : ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;

        case 2:
            printf("Enter Key for searching: ");
            scanf("%d", &key);
            s = search(root, key);
            if (s != NULL)
                printf("Key %d found in the binary tree.\n", key);
            else
                printf("Key %d not found in the binary tree.\n", key);
            break;

        case 3:
            printf("Enter Key of node you want to Delete from BST:");
            scanf("%d", &deletekey);
            root = deleteNode(root, deletekey);
            break;

        case 4:
            printf("Tree (Inorder Traversal)\n");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting....\n");
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}