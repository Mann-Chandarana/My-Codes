package Pratice.Java;

import java.util.Scanner;  // Importing Scanner class


public class PackageImporting  // Creating a class name "PackageImporting"
{
    public void Done()  // Creating a meber function "Done"
    {
        System.out.println("the user defined package is successfully imported !!");  // Printing message
        System.out.println("package implemented succesfully!!");                     // Printing message
    }
}

class Practice1
{
    public static void main(String[] args)
    {
        int a = 25;
        String s = Integer.toString(a);
        System.out.println(((Object)a).getClass().getSimpleName()); // TO know the type of variable
        Scanner sc = new Scanner(System.in);
        //System.out.printf("My num is %d",a);
        //System.out.println(4.8%3.3);

    }
}
