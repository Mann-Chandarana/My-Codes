#include<stdio.h>

int main()
{
    char input;
    float kmsTomiles =0.621371;
    float inchesTofoot =0.083333;
    float cmsToinches =0.393701;
    float poundsTokgs =0.453592;
    float inchesToMeters=0.0254;
    float first,second;

    while (1)
    {
        printf("Enter the input character.q to quit\n      1. km to miles\n      2. inches to foot\n      3. cms to inches\n      4. pounds to kg\n      5. inches to meters\n");
        scanf(" %c",&input);
        printf("The character is'%c\n",input);

        switch (input)
        {
        case 'q':
        printf("Quiting the program...");       
            goto end;
            break;

        case '1':
        printf(" Enter first quantity in terms of first unit\n");
        scanf("%f",&first);
        second = first*kmsTomiles;
        printf("%f kms is equal to %f miles\n",first,second);
            break;

        case '2':
        printf(" Enter first quantity in terms of first unit\n");
        scanf("%f",&first);
        second = first*inchesTofoot;
        printf("%f inches is equal to %f foot\n",first,second);
            break;

        case '3':
        printf(" Enter first quantity in terms of first unit\n");
        scanf("%f",&first);
        second = first*cmsToinches;
        printf("%f cms is equal to %f inches\n",first,second);
            break;

        case '4':
        printf(" Enter first quantity in terms of first unit\n");
        scanf("%f",&first);
        second = first*poundsTokgs;
        printf("%f pounds is equal to %f kgs\n",first,second);
            break;

        case '5':
        printf(" Enter first quantity in terms of first unit\n");
        scanf("%f",&first);
        second = first*inchesToMeters;
        printf("%f inchesis equal to %f meters\n",first,second);
            break;
        
        }
    }
    end:
    return 0;
}
