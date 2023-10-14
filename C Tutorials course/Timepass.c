#include <stdio.h>

int main()
{
    int Costprice, Sellingprice, Totalloss, Totalprofit;
    printf("Enter Cost price:\n");
    scanf("%d", &Costprice);
    printf("Enter Selling price:\n");
    scanf("%d", &Sellingprice);

    if (Costprice > Sellingprice)
    {
        printf("You are in loss\n");
        Totalloss = Costprice - Sellingprice;
        printf("Loss : %d\n", Totalloss);
    }
    else if (Costprice < Sellingprice)
    {
        printf("You are in profit\n");
        Totalprofit = Sellingprice - Costprice;
        printf("Profit : %d\n", Totalprofit);
    }
    else if (Costprice = Sellingprice)
    {
        printf("You are not in loss nor in profit\n");
    }
    else
    {
        printf("Enter amount in Digits\n");
    }
    

    return 0;
}