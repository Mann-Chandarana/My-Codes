package College;
import java.util.Scanner;   // Importing Scanner class
import java.util.Vector;    // Importing Vector class

interface IPrinter       // Creating interface name "IPrinter"
{
    public void func1();
}

interface  IScanner      // Creating interface name "IScanner"
{
     public void func2(int j);
}

class Concrete implements IPrinter,IScanner    // Creating a class name "Concrete" and implements "IPrinter" and "IScanner"
{
    private int n;    // Creating a private data member name "n" of return type integer

    @Override
    public void func1()  // Creating a member function name "func1"
    {
        System.out.println("We are in func1");   // Printing message
        System.out.println("And your number is "+n +"\n");    // Printing message
    }

    @Override
    public void func2(int j)    // Creating a member function name "func2"
    {
        Scanner sc = new Scanner(System.in);   // Creating a object name "sc" of class name "Scanner"
        System.out.println("Enter the number "+j);  // Printing message
        n = sc.nextInt();  // Taking input from the users
    }
}

public class Practical_03_02
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Vector<Concrete> Vec1 = new Vector<>(5);   // Creating a vector of name "Vec1" of type class "Concrete"

        int j = 1;
        for (int i = 0;i<5;i++)
        {
            Concrete C = new Concrete();  // Creating a object name "C" of class "Concrete"
            C.func2(j);   // Calling member function "func2"
            Vec1.add(C);   // Adding object of class "Concrete" in a vector
            j++;
        }

        for (int i = 0;i<5;i++)
        {
            Vec1.get(i).func1();   // Printing all values
        }
    }
}
