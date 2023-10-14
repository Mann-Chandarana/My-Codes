package College;

import java.util.*;

public class Practical_04_01
{
    public static void main(String []args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        try                                          // Using try block
        {
            System.out.println("\n1st Try Block.");  // Printing message
            System.out.println(10/0);
        }
        catch(ArithmeticException e)                // Catching error using catch block
        {
            System.out.println(e);                  // Printing error
        }
        try                                          // Using try block
        {
            System.out.println("\n2nd Try Block.");  // Printing message
            int [] arr = new int[5];                 // Creating a array of type int name "arr"
            int i = arr[6];
        }
        catch(ArrayIndexOutOfBoundsException e)      // Catching error using catch block
        {
            System.out.println(e);                   // Printing error
        }
        try                                          // Using try block
        {
            System.out.println("\n3rd Try Block.");  // Printing message
            String a = null;                         // Creaing a variable name "a" of type string
            System.out.println(a.charAt(0));         // Printing message
        }
        catch(NullPointerException e)                // Catching error using catch block
        {
            System.out.println("NullPointerException.");      // Printing message
        }
    }
}