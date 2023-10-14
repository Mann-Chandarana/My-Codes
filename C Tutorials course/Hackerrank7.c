#include <stdio.h>
#include <stdlib.h>
int *books;
int **number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d\n", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    books = (int *)calloc(total_number_of_shelves, sizeof(int));
    number_of_pages = (int **)calloc(total_number_of_shelves, sizeof(int));

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        books[i] = 0;
        number_of_pages[i] = (int *)malloc(sizeof(int));
    }

    while (total_number_of_queries--)
    {
        int types_of_queries;
        scanf("%d", &types_of_queries);

        if (types_of_queries == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            books[x]++;
            number_of_pages[x] = realloc(number_of_pages[x], books[x] * sizeof(int));
            number_of_pages[x][books[x] - 1] = y;
        }
        else if (types_of_queries == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d", number_of_pages[x][y]);
        }
        else if (types_of_queries == 3)
        {
            int x;
            scanf("%d", &x);
            printf("%d", books[x]);
        }
        
    }
    if (books)
        {
            free(books);
        }

        for (int i = 0; i < total_number_of_shelves; i++)
        {
            if (*(number_of_pages + i))
            {
                free(*(number_of_pages + i));
            }
        }

        if (number_of_pages)
        {
            free(number_of_pages);
        }

    return 0;
}