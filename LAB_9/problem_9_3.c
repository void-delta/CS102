#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Student{
    char name[50];
    int grade;
    struct Student *left;
    struct Student *right;
} Student;

Student *insert(Student *root, char name[50], int grade){
    Student *new_node = (Student *)malloc(sizeof(Student));
    if (root == NULL){
        strcpy(new_node->name, name);
        new_node->grade = grade;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }

    if (strcmp(name, root->name) < 0){
        root->left = insert(root->left, name, grade);
    }
    else if (strcmp(name, root->name) > 0){
        root->right = insert(root->right, name, grade);
    }
    else{
        new_node->grade = grade;
    }

    return root;
}

Student *search(Student *root, char name[50]){
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

void displayInorder(Student *root){
    if (root != NULL){
        displayInorder(root->left);
        printf("Name: %s\tGrade: %d\n", root->name, root->grade);
        displayInorder(root->right);
    }
}

Student *findMinGrade(Student *root){
    if (root == NULL){
        return NULL;
    }
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

Student *findMaxGrade(Student *root){
    if (root == NULL){
        return NULL;
    }
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

int main(){
    Student *root = NULL;
    char name[50];
    int grade, choice;

    do{
        printf("-----Student Report Card-----\n\n");
        printf("1) Insertion\n2) Searching\n3) Display\n4) Minimum Grade\n5) Maximum Grade\n6) Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("\nEnter the Name to be inserted: ");
            scanf("%s", name);
            printf("Enter the Grade to be inserted: ");
            scanf("%d", &grade);
            root = insert(root, name, grade);
            break;

        case 2:
            printf("\nEnter the Name for searching: ");
            scanf("%s", name);
            Student *foundStudent = search(root, name);
            if (foundStudent != NULL){
                printf("\nContact Found!\n");
                printf("Name: %s\tGrade: %d\n\n", foundStudent->name, foundStudent->grade);
            }
            else{
                printf("\nNo entry found with that name.\n");
            }
            break;

        case 3:
            printf("\nDisplaying Contacts...\n");
            displayInorder(root);
            printf("\n\n");
            break;

        case 4:{
            Student *minGrade = findMinGrade(root);
            if (minGrade != NULL){
                printf("Lowest performing Student\n");
                printf("Name: %s\tGrade: %d\n", minGrade->name, minGrade->grade);
            }
            else{
                printf("No student records found.\n");
            }
            break;
        }

        case 5:{
            Student *maxGrade = findMaxGrade(root);
            if (maxGrade != NULL){
                printf("Highest performing Student\n");
                printf("Name: %s\tGrade: %d\n", maxGrade->name, maxGrade->grade);
            }
            else{
                printf("No student records found.\n");
            }
            break;
        }

        case 6:
            printf("Exiting...\n");
            free(root);
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (1);

    return 0;
}