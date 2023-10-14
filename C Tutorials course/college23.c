#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct book
{
    int b_no;
    char b_name[40];
    char b_author[40];
    int no_pages;
};

int main()
{
    struct book b[10];
    int ch, n, count = 0;
    char temp[40];

    do
    {
        printf("\t Menu\n");
        printf("---------------------------------\n");
        printf("Press 1 To Add book details.\n");
        printf("Press 2 To Display book details.\n");
        printf("Press 3 To Display book of given author.\n");
        printf("Press 4 To count number of book.\n");
        printf("Press 5 To Exit.\n");
        printf("---------------------------------\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nHow Many records You want to ADD:\n");
            scanf("%d", &n);
            printf("\n---------------------------------\n");
            printf("Add Details of %d Books\n", n);
            printf("---------------------------------\n");

            for (int i = 0; i < n; i++)
            {
                printf("Enter Book No.:");
                scanf("%d", &b[i].b_no);
                printf("Enter Book Name.:");
                scanf("%s", &b[i].b_name);
                printf("Enter Author Name.:");
                scanf("%s", &b[i].b_author);
                printf("Enter Number of pages.:");
                scanf("%d", &b[i].no_pages);
                printf("\n---------------------------------\n");
            }
            break;

        case 2:
            printf("\n\t\tDetails of All Book\n");
            printf("---------------------------------\n");
            printf("Book No.Book Name\t Author Name\tNumber of Pages\n");
            printf("---------------------------------\n");

            for (int i = 0; i < n; i++)
            {
                printf("\n %d\t %s\t\t %s\t\t %d", b[i].b_no, b[i].b_name, b[i].b_author, b[i].no_pages);
            }
            printf("\n\n");
            break;

        case 3:
            printf("\nEnter Author Name: \n");
            scanf("%s", &temp);
            printf("\n---------------------------------\n");

            for (int i = 0; i < n; i++)
            {
                if (strcmp(b[i].b_author, temp) == 0)
                {
                    printf("\n%s\n", b[i].b_name);
                }
            }
            break;

        case 4:

            for (int i = 0; i < n; i++)
            {
                count++;
            }
            printf("\nTotal Number of Books in Library : %d\n", count);
            printf("---------------------------------\n");
            break;

        case 5:
            exit(0);
        }
    } while (ch!=5);

    return 0;
}