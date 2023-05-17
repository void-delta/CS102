/* Write a C prograqm thta dynamically allocates the memory for a struct of books that has 
   title of the book, author name, and year of publication. Get a prompt for the number if 
   books by the user */

#include <stdio.h>
#include <stdlib.h>

typedef struct book{
    char title[30];
    char author[30];
    int year;
}book;

int main()
{
    printf("Enter the Number of Books\t");
    int n;
    scanf("%d", &n);

    book *bookptr;
    bookptr = (book*)malloc(n*sizeof(book));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the Title of the Book\t");
        scanf("%s", bookptr[i].title);
        printf("ENter the Author of the Book\t");
        scanf("%s", bookptr[i].author);
        printf("ENter the Year of Publishing\t");
        scanf("%d", &bookptr[i].year);
    }

    for(int i = 0; i < n; i++)
    {
        printf("Title of the Book\t%s\n", bookptr[i].title);
        printf("Author of the Book\t%s\n", bookptr[i].author);
        printf("Year of Publishing of the Book\t%s\n", bookptr[i].year);
    }

    return 0;
}