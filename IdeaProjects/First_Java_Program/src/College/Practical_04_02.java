package College;

import java.util.Scanner;                             // Importing Scanner class

class InvalidAgeException  extends Exception          // Creating a class name "InvalidAgeException" which extends Exception
{
    public InvalidAgeException (String str)           // Parameterized constructor
    {
        super(str);                                  // calling super class constructor
    }
}

public class Practical_04_02
{

    static void validate (int age) throws InvalidAgeException      // Creaing a function name "validate" with throws Exception
    {
        if(age < 18)
        {
            throw new InvalidAgeException("Not eligible to Vote!\n");         // Throwing InvalidAgeException
        }
        else
        {
            System.out.println("You are eligile to vote.\n");                // Printing message
        }
    }

    public static void main(String args[])
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");

        Scanner sc = new Scanner(System.in);   // Creating scanner class object name "sc"

        int age;                             // Creating a variable name "age" of type int
        int count = 0;                       // Creating a variable name "count" of type int
        while (count !=2)
        {
            try                                 // Using try block
            {
                System.out.println("Enter your age");
                age = sc.nextInt();
                count++;
                validate(age);              // Calling function name "validate"
            }
            catch (InvalidAgeException e)      // Catching error
            {
                System.out.println("\nException occured: " + e);    // Printing message
            }
        }
    }
}