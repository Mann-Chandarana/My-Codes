/* - In a town, the percentage of men is 52. The percentage of total literacy is 48. If total percentage of literate men is 35 of the 
total population, write a program to find the total number of illiterate men and women if the population of the town is 80,000.*/

#include<stdio.h>

int main()
{
    long int Totalpopulation=80000,Totalmen,Totalwoman,TotalLiteracy,Literatemen,Literatewoman,Totalilliteracy,Illiteratemen,Illiteratewoman;
    printf("\nThe Total population is %ld",Totalpopulation);

    Totalmen = 0.52*Totalpopulation;
    printf("\nTotal men is %ld",Totalmen);

    Totalwoman = Totalpopulation-Totalmen;
    printf("\nTotal woman is %ld",Totalwoman);

    TotalLiteracy = 0.48*Totalpopulation;
    printf("\nTotal literate person are %ld",TotalLiteracy);

    Literatemen = 0.35*Totalpopulation;
    printf("\nTotal Literate men are %ld",Literatemen);

    Literatewoman = TotalLiteracy - Literatemen;
    printf("\nTotal woman are %ld",Literatewoman);

    Totalilliteracy = Totalpopulation-TotalLiteracy;
    printf("\nTotal illerate person are %ld",Totalilliteracy);

    Illiteratemen = Totalmen-Literatemen;
    printf("\nTotal illerate men are %ld",Illiteratemen);

    Illiteratewoman = Totalwoman-Literatewoman;
    printf("\nTotal illerate woman are %ld",Illiteratewoman);

    return 0;

}