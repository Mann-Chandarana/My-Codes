#include <stdio.h>

struct Bookdetails
{
    char name[20];
    char author[20];
    int pages;
    float price;
};

void output(struct Bookdetails v[], int n);

void main()
{
    struct Bookdetails b[10];
    int num;
    printf("Enter the number of books :\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\n Book %d Detail :=\n\n", i + 1);

        printf("Enter the book name :\n");
        scanf("%s", &b[i].name);

        printf("Enter the author of the book :\n");
        scanf("%s", &b[i].author);

        printf("Enter the Pages of book :\n");
        scanf("%d", &b[i].pages);

        printf("Enter the price of the book :\n");
        scanf("%f", &b[i].price);
    }
    output(b, num);
}
void output(struct Bookdetails v[], int n)
{
    int t = 1;
    for (int i = 0; i < n; i++, t++)
    {
        printf("\n");
        printf("Book No.%d\n\n", t);
        printf("\t\t Book %d name is %s\n", t, v[i].name);
        printf("\t\t Book %d author is %s\n", t, v[i].author);
        printf("\t\t Book %d pages are %d\n", t, v[i].pages);
        printf("\t\t Book %d price is %f\n", t, v[i].price);
        printf("\n");
    }
}
