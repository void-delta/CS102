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

void display_pre(struct node *root){
    struct node *temp = root;
    if(temp != NULL){
        printf("%d ", temp->data);
        display_pre(temp->left);
        display_pre(temp->right);
    }
    return;
}

void display_pos(struct node *root){
    struct node *temp = root;
    if(temp != NULL){
        display_pos(temp->left);
        display_pos(temp->right);
        printf("%d ", temp->data);
    }
    return;
}

int main(){
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    int n, count = 1;
    printf("Enter the number of elements in the TREE\t");
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        ins(i, root, &count);
    }
    printf("PRE_ORDER:-\n");
    display_pre(root);
    printf("\n");

    printf("IN_ORDER:-\n");
    display_in(root);
    printf("\n");

    printf("POST_ORDER:-\n");
    display_pos(root);
    printf("\n");

    return 0;
}