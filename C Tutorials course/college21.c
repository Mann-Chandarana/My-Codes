#include <stdio.h>

int non_rec_bin(int num);
int rec_bin(int num);

int main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d", &num);

    printf("Decimal to binary Using recursion %d\n", rec_bin(num));
    printf("Decimal to binary without Using recursion %d\n", non_rec_bin(num));

    return 0;
}
int rec_bin(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return ((num % 2) + 10 * rec_bin(num / 2));
    }
}

int non_rec_bin(int num)
{
    int x, res = 0, pos = 1;
    while (num != 0)
    {
        x = num % 2;
        res = res + (x * pos);
        pos = 10 * pos;
        num = num / 2;
    }
    return res;
}