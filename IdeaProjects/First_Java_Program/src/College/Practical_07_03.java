package College;

import java.util.ArrayList;     // Importing "ArrayList" class
import java.util.Scanner;      //  Importing "Scanner" class

class AccountHolder           // Creating a class name "AccountHolder"
{
    public String name,Citizenship;           // Creating a data members of type "String"
    public int Net_Income,Work_experience,age;   // Creating a data members of type "int"

    AccountHolder(String name,int age,String Citizenship,int Net_Income,int Work_experience) // Creating Parametrized Constructor
    {
        this.name = name;
        this.Citizenship = Citizenship;
        this.age = age;
        this.Work_experience = Work_experience;
        this.Net_Income = Net_Income;
    }
}
public class Practical_07_03
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        String name,Citizenship;            // Creating variables of type "String"
        int age,Net_Income,Work_experience;   // Creating a variable of type "int"
        Scanner sc = new Scanner(System.in);   // Creating a object name "sc" of class "Scanner"

        ArrayList<AccountHolder> list = new ArrayList<AccountHolder>();   // Creating a ArrayList name "list" containing elements of type "AccountHolder"

        for (int i = 0; i < 5; i++)
        {
            System.out.println((i+1)+")\nEnter your name");  // Printing message
            name = sc.next();                               // Taking input from the user

            System.out.println("Enter your age");            // Printing message
            age = sc.nextInt();                              // Taking input from the user

            System.out.println("Enter your citizenship");     // Printing message
            Citizenship = (sc.next()).toUpperCase();          // Taking input from the user

            System.out.println("Enter your net Income");       // Printing message
            Net_Income = sc.nextInt();                         // Taking input from the user

            System.out.println("Enter your work experience");     // Printing message
            Work_experience = sc.nextInt();                       // Taking input from the user

            list.add(new AccountHolder(name,age,Citizenship,Net_Income, Work_experience));  // Adding elements in list
            System.out.print("\n");                                                        // Printing new line
        }

        System.out.println("Eligible people are :-");              // Printing message
        for (int i = 0; i < 5; i++)
        {
            if ((list.get(i).age>=21 && list.get(i).age<=60) && (list.get(i).Net_Income>=15000)&&(list.get(i).Work_experience>=1)
                && (list.get(i).Citizenship.equals("INDIAN")))
            {
                System.out.println(i+1 +") "+ list.get(i).name);        // Printing message
            }
        }
    }
}
