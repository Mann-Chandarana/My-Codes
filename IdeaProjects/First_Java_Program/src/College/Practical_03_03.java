package College;

interface P1   // Creating interface name "P1"
{
    final int n1=1;    // Creating constant variable name "n1" of type integer
    void func1();      // Declaring a function name "func1"
}

interface P2   // Creating interface name "P1"
{
    final int n2=2;    // Creating constant variable name "n2" of type integer
    void func2();      // Declaring a function name "func2"
}

interface P extends P1,P2   // Creating a interface name "P" extends interface name "P1" and "P2"
{
    final int n3=3;    // Creating constant variable name "n3" of type integer
    void func3();      // Declaring a function name "func3"
}

class ABC implements P   // Creating a class name "ABC" implements name "P"
{
    @Override
    public void func1()  // Overiding name "func1"
    {
        System.out.println("We are inside func " +n1);   // Printing message
    }

    @Override
    public void func2()   // Overiding name "func2"
    {
        System.out.println("We are inside func " +n2);  // Printing message
    }

    @Override
    public void func3()   // Overiding name "func3"
    {
        System.out.println("We are inside func " +n3);   // Printing message
    }
}

public class Practical_03_03
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        ABC obj = new ABC();  // Creating a object name "obj" of class name "ABC"
        obj.func1();   // Calling member function name "func1"
        obj.func2();   // Calling member function name "func2"
        obj.func3();   // Calling member function name "func3"
    }
}
