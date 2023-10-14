package College;

import java.util.Scanner;           // Importing Scanner class

public class Practical_04_03
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        int a, b, c;                      // Creating three variable name "a","b","c" of type integer
        Scanner sc = new Scanner(System.in);   // Creating a scanner object name "sc"
        int[] arr = new int[5];               // Creating a array name "arr" of type integer
        int count = 0;                       // Creating a variable name "count" of type integer
        while (count!=2)
        {
            System.out.println("Enter the index number in which you want to put the number");   // Printing message
            a = sc.nextInt();                                                                  // Taking input from the user
            System.out.println("Enter two number in which you want divison");                  // Printing message
            b = sc.nextInt();            // Taking input from the user
            c = sc.nextInt();            // Taking input from the user
            count++;

            try                          // Using try block
            {
                arr[a] = b;
                System.out.println(b / c);
            }

            catch (ArithmeticException E)        // Catching error
            {
                System.out.println("Arithmetic exception caught");      // Printing message
            }

            catch (ArrayIndexOutOfBoundsException E)          // Catching error
            {
                System.out.println("Given value is out of bound\n");     // Printing message
            }
            finally                                                  // Using finally block
            {
                System.out.println("Your Important! task is completed\n");       // Printing message
                System.out.println("****************************************************************\n");
            }
        }
    }
}
