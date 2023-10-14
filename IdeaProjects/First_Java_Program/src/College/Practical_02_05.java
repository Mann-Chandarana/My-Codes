package College;

public class Practical_02_05
{
    public static void sum(int n1,int n2)  // Creating a method name "sum" with two parameters
    {
        System.out.println("Sum of two number is "+(n1+n2));   // Printing sum of two number
    }

    public static void sum(int n1,int n2,int n3)   // Creating a method name "sum" with three parameters
    {
        System.out.println("Sum of three number is "+(n1+n2+n3));   // Printing sum of three number
    }

    public static void sum(int ...arr)    // Creating a method name "sum" with indefinite parameters
    {
        int result = 0;                  // Creating a variable name "result"

        for (int ele:arr)
        {
            result+=ele;
        }

        System.out.println("Sum of numbers is "+result);   // Printing sum
    }

    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        sum(1,2);                 // Calling "sum" function with two arguments
        sum(3,4,5);              // Calling "sum" function with three arguments
        sum(6,7,8,9,10,11);   // Calling "sum" function with indefinite arguments
    }
}

