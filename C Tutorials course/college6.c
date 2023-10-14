#include <stdio.h>

int main()
{
    int Net_Salary, Basic_Salary, Allowances, Deduction;
    int DA, MA, HRA, TA, PF, IT = 500;
    printf("Enter your Basic Salary\n");
    scanf("%d", &Basic_Salary);
    DA = 0.7*Basic_Salary;
    HRA = Basic_Salary * 0.07;
    MA = Basic_Salary * 0.02;
    TA = Basic_Salary * 0.04;
    Allowances = DA + HRA + MA + TA;
    printf("Allowances are %d\n", Allowances);
    PF = Basic_Salary * 0.12;
    Deduction = PF + IT;
    printf("Deduction are %d\n", Deduction);
    Net_Salary = Basic_Salary + Allowances + Deduction;
    printf("Your net salary is %d", Net_Salary);

    return 0;
}