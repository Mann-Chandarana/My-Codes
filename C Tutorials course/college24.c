#include <stdio.h>
struct employee
{
    int age;
    float salary;
    char id[10],name[25];
}
emp[10];

void main()
{
    int i,n;
    printf("Enter the number of employee : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("\n\t=: Employee %d Detail :=\n",i+1);
        
        printf("Enter the Employee ID :");
        scanf("%s",emp[i].id); 

        printf("\nEnter the Employee name :");
        scanf("%s",emp[i].name);

        printf("\nEnter the Employee salary :");
        scanf("%f",&emp[i].salary);

        printf("\nEnter the Employee Age :");
        scanf("%d",&emp[i].age);
    }
    printf("\n \nEmp_ID\t\tEmp_Name\tEmp_Salary\tEmp_Age\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%s\t\t%f\t\t%d\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].age);
    }
}