#include<stdio.h>

int main()
{
    int Totalamount=5879,HundredNotes,FiftyNotes,TenNotes,FiveCoins,TwoCoins,Amountleft;

    printf("\n The Total amount is %d\n",Totalamount);

    HundredNotes= Totalamount/100;
    printf("\n The Total Hundred Rupees Notes are %d\n",HundredNotes);

    Amountleft = Totalamount%100;
    printf("\n The Total Amount left are %d\n",Amountleft);

    FiftyNotes = Amountleft/50;
    printf("\n The Total Fifty Rupees Notes are %d\n",FiftyNotes);

    Amountleft = Totalamount%50;
    printf("\n The Total Amount left are %d\n",Amountleft);

    TenNotes = Amountleft/10;
    printf("\n The Total Ten Rupees Notes are %d\n",TenNotes);    
    
    Amountleft = Totalamount%10;
    printf("\n The Total Amount left are %d\n",Amountleft);

    FiveCoins = Amountleft/5;
    printf("\n The Total five Rupees Coins are  %d\n",FiveCoins);

    Amountleft = Totalamount%5;
    printf("\n The Total Amount left are %d\n",Amountleft);

    TwoCoins = Amountleft/2;
    printf("\n The Total two Rupees Coins are  %d\n",TwoCoins);

    Amountleft = Totalamount%2;
    printf("\n The Total Amount left are %d\n",Amountleft);

    return 0;

    
}

