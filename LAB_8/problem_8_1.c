/* Write a C program to implement various operations of a Binary tree such as 
Insert, Search, Display
(you can use the inorder traversal for the display) and Deleting a specified key.
Use the below logic for the insertion:
if(count%2==0)
r->LEFT = insert(r->LEFT, n);
else
r->RIGHT = insert(r->RIGHT, n);
where count is the variable keeping track of the items in the binary tree */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void ins(int info, struct node *root, int *count){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    struct node *temp = root;
    new->data = info;
    new->left == NULL;
    new->right == NULL;
    *count = *count + 1;
    if(*count%2 == 0){
        while(temp->left != NULL){
            temp = temp->left;
        }
        temp->left = new;
    }
    else{
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = new;
    }
    return;
}

void delete(struct node **root, int *count){
    struct node *temp = *root;
    int n = 0;
    while(n != 1 || n != 2){
        printf("1)Go_Left 2)Go_Right\t");
        scanf("%d", &n);
    }
    if(n == 1){
        while(temp->left->left != NULL){
            temp = temp->left;
        }
        free(temp->left);
    }
    else{
        while(temp->right->right != NULL){
            temp = temp->right;
        }
        free(temp->right);
    }
    printf("DONE\n\n");
    return;
}

void display_in(struct node *root){
    struct node *temp = root;
    if(temp != NULL){
        display_in(temp->left);
        printf("%d ",temp->data);
        display_in(temp->right);
    }
    return;
}

void search(int info, struct node *root){
    struct node *temp = root;
    while(temp != NULL){
        if(temp->data == info){
            printf("Found %d\n", temp->data);
            return;
        }
        search(info, temp->left);
        //printf("%d ",temp->data);
        search(info, temp->right);
    }
    printf("Not Found\n");
    return;
}


int main(){
    struct node *root = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Element of the root\t");
    int d;
    scanf("%d", &d);
    root->data = d;
    root->left = NULL;
    root->right = NULL;
    int count = 1;
    while(1){
        printf("\n1)Insert 2)Delete 3)Seearch 4)Display 5)Exit\t");
        int x;
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter the Element:\t");
                int s;
                scanf("%d", &s);
                ins(s, root, &count);
                break;
            case 2:
                printf("Deleting.....\n");
                scanf("%d", &s);
                delete(&root, &count);
                break;
            case 3:
                printf("Enter searching element\t");
                scanf("%d", &s);
                search(s, root);
                break;
            case 4:
                display_in(root);
                break;
            case 5:
                return 0;
            default:
                printf("Wrong Input\n");
        }
    }
    return 0;
}