#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct PhonebookEntry{
    char name[50];
    char phoneNumber[15];
    struct PhonebookEntry *left;
    struct PhonebookEntry *right;
} PhonebookEntry;

PhonebookEntry *insert(PhonebookEntry *root, char name[50], char phoneNumber[15]){
    PhonebookEntry *new_node = (PhonebookEntry *)malloc(sizeof(PhonebookEntry));
    if (root == NULL){
        strcpy(new_node->name, name);
        strcpy(new_node->phoneNumber, phoneNumber);
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }

    if (strcmp(name, root->name) < 0){
        root->left = insert(root->left, name, phoneNumber);
    }
    else if (strcmp(name, root->name) > 0){
        root->right = insert(root->right, name, phoneNumber);
    }
    else{
        strcpy(new_node->phoneNumber, phoneNumber);
    }

    return root;
}

PhonebookEntry *search(PhonebookEntry *root, const char name[50]){
    if (root == NULL || strcmp(name, root->name) == 0){
        return root;
    }
    if (strcmp(name, root->name) < 0){
        return search(root->left, name);
    }
    else if (strcmp(name, root->name) > 0){
        return search(root->right, name);
    }
    return NULL;
}

void displayInorder(PhonebookEntry *root){
    if (root != NULL){
        displayInorder(root->left);
        printf("Name: %s\tPhone number: %s\n", root->name, root->phoneNumber);
        displayInorder(root->right);
    }
}

int main(){
    PhonebookEntry *root = (PhonebookEntry *)malloc(sizeof(PhonebookEntry));
    root = NULL;
    char name[50], phoneNumber[15];
    int choice;

    do{
        printf("-----Phone Book Entry Program-----\n\n");
        printf("1)Insertion\n2)Searching\n3)Display\n4)Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("\nEnter the Name to be inserted:");
            scanf("%s", name);
            printf("\nEnter the Phone Number to be inserted:");
            scanf("%s", phoneNumber);
            root = insert(root, name, phoneNumber);
            break;

        case 2:
            printf("\nEnter the Name for searching:");
            scanf("%s", name);
            root = search(root, name);
            if (root != NULL){
                printf("\nContact Found!\n");
                printf("Name: %s\tPhone number: %s\n\n", root->name, root->phoneNumber);
            }
            else{
                printf("\nNo entry found with that name.");
            }
            break;

        case 3:
            printf("\nDisplaying Contacts......\n");
            displayInorder(root);
            printf("\n\n");
            break;

        case 4:
            printf("Exiting....\n");
            free(root);
            exit(0);
            break;

        default:
            printf("Invalid\n");
            continue;
        }
    } while (choice != 4);

    return 0;
}