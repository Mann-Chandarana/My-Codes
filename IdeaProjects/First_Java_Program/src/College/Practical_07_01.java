package College;

import java.util.Scanner;               // Importing "Scanner" class

class Sort<t1 extends Comparable<t1>>    // Creating a class name "Sort" using Generic name "t1"
{
    public void sort(t1 []arr)           // Creating a method name "sort"
    {
        t1 temp;                            // Creating a variable name "temp" of type "t1"
        for (int i = 0; i < arr.length; i++)
        {
            for (int j = i+1; j < arr.length; j++)
            {
                if (arr[i].compareTo(arr[j])>0)    // Comparing values and swapping values
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
public class Practical_07_01
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        System.out.println("Enter the number of integer you want to add in array");  // Printing message
        Scanner sc = new Scanner(System.in);   // Creating a object name "sc" of class "Scanner"
        int no = sc.nextInt();                 // Taking input from the user
        Integer []arr = new Integer[no];      // Creating an array of type "Integer"

        for (int i = 0; i < no; i++) 
        {
            System.out.println("Enter number "+(i+1));   // Printing message
            arr[i] = sc.nextInt();                      // Taking input from the user
        }

        Sort<Integer> s1 = new Sort<Integer>();              // creating a object name "s1" of type "Integer"
        s1.sort(arr);                                  // Calling "sort" method

        System.out.println("\nYour numbers after sorting");   // Printing message
        for (int i = 0; i < no; i++)
        {
            System.out.println(arr[i]);                      // Printing array numbers
        }
    }
}
