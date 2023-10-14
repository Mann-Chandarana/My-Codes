#include<stdio.h>
int main()
{
    //Suppose we have only 100 product (Quantity of product) in stock
    int stock=100, order;
    char credit;

    printf("Enter the customer order:\n ");
    scanf("%d", &order);
    //check for customer credit
    printf("Is his credit is ok? (Press y/n)\n");
    credit = getch();   //it receive only one character

    //check for rule (i)
    if(order<=stock && credit == 'y' || credit == 'Y') //user may enter capital letter also
        printf("Sir,\n\t We supplied your requirement\n\t\t Quantity: %d",order);

    //check for rule (ii)
    else if(order>stock && credit == 'y' || credit == 'Y')
        printf("Sir,\n\t We supplied %d products and balance will be shipped later.",stock);

    //check for rule (iii)
    else
        printf("Sir,\n\t Please first clear your credit, until we can't supply you any more.");
}