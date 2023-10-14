//  You manage a travel agency, and you want your n drivers to input their following details:

// Name of the driver
// Driving License Number
// Route
// Kms
// Your program should be able to take n as input (or you can take n=3 for simplicity), and your drivers will start inputting
//  their details one by one. Your program should print details of the drivers in a beautiful fashion.
#include <stdio.h>
struct Driver
{
     char name[34];
     char dlno[45];
     char route[47];
     int kms;
};
int main()
{
     struct Driver d1, d2, d3;
     printf("Enter the Details of Driver No 1\n");

     printf("Enter the name of first driver\n");
     scanf("%s", &d1.name);

     printf("Enter dlno of first driver\n");
     scanf("%s", &d1.dlno);

     printf("Enter the route of first driver\n");
     scanf("%s", &d1.route);

     printf("Enter the number of kms first driver\n");
     scanf("%d", &d1.kms);

     printf("Enter the Details of Driver No 2\n");

     printf("Enter the name of second driver\n");
     scanf("%s", &d2.name);

     printf("Enter dlno of second driver\n");
     scanf("%s", &d2.dlno);

     printf("Enter the route of second driver\n");
     scanf("%s", &d2.route);

     printf("Enter the number of kms second driver\n");
     scanf("%d", &d2.kms);

     printf("Enter the Details of Driver No 3\n");

     printf("Enter the name of third driver\n");
     scanf("%s", &d3.name);

     printf("Enter dlno of third driver\n");
     scanf("%s", &d3.dlno);

     printf("Enter the route of third driver\n");
     scanf("%s", &d3.route);

     printf("Enter the number of kms third driver\n");
     scanf("%d", &d3.kms);

     printf("******Printing information of Drivers******");
     printf("For Driver No 1:\n Name is %s\n", d1.name);
     printf("DL number is %s\n", d1.dlno);
     printf("Route is %s\n", d1.route);
     printf("KMS is %d\n", d1.kms);

     printf("For Driver No 2:\n Name is %s\n", d2.name);
     printf("DL number is %s\n", d2.dlno);
     printf("Route is %s\n", d2.route);
     printf("KMS is %d\n", d2.kms);

     printf("For Driver No 3:\n Name is %s\n", d3.name);
     printf("DL number is %s\n", d3.dlno);
     printf("Route is %s\n", d3.route);
     printf("KMS is %d\n", d3.kms);

     return 0;
}
