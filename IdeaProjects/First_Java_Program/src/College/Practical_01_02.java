package College;
import java.util.Scanner;

public class Practical_01_02
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Scanner sc = new Scanner(System.in); // Creating Scanner class object (sc)

        String Phone_Number; // Creating a variable name Phone_number of type string

        System.out.println("Enter your number "); // Printing message

        Phone_Number = sc.next(); // Taking input from the user

        String code = Phone_Number.substring(4,6); // Creating variable name code and using substring method of class string

        System.out.println("Mobile system operator code is "+ code); // Printing message

        code = Phone_Number.substring(7,10); // Using substring method of class string

        System.out.println("MSC is "+code); // Printing message

        code = Phone_Number.substring(11,16); // Using substring method of class string

        System.out.println("Unique code is "+code); // Printing message

    }
}
