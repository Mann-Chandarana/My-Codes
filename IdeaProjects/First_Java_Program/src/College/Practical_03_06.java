package College;

import Pratice.Java.PackageImporting;  // Importing class name "PackageImporting" from "practice.java" package

class Greet  // Creating a class name "Greet"
{
    void Greeting()      // Creating a method name "Greeting"
    {
        System.out.println("Good Morning");   // Printing message
    }
}

public class Practical_03_06
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        PackageImporting obj = new PackageImporting();  // Creating a object name "obj" of class name "PackageImporting"
        obj.Done();              // Calling a function name "Done"

        System.out.println("\n");      // Printing new-line

        Greet G = new Greet();   // Creating a object name "G" of class name "Greet"
        G.Greeting();            // Calling a function name "Greeting"
    }
}
