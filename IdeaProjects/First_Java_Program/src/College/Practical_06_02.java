package College;

import java.util.Random;

class Mythr1 extends Thread          // Creating class name "Mythr1" extending Thread
{
    public int []arr ;              // Creating array of return type int name "arr"

    public Mythr1(int []a)          // Creating parametrized Constructor
    {
        arr = a;
    }

    @Override
    public void run()                    // Overriding method "run" of super class
    {;
        int i = 1;
        int j = i;
        while (j < arr.length)
        {
            System.out.println(arr[j]);
            i++;
            j = (2*i + 1);
        }
    }
}

class Mythr2 extends Thread          // Creating class name "Mythr2" extending Thread
{
    public int []arr;              // Creating array of return type int name "arr"

    public Mythr2(int []a)           // Creating parametrized Constructor
    {
        arr = a;
    }

    @Override
    public void run()                 // Overriding method "run" of super class
    {
        int i = 0;
        int j = 0;
        while (j < arr.length)
        {
            j = (2*i);
            System.out.println(arr[i]);
            i++;
        }
    }
}

public class Practical_06_02
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");

        System.out.println("Generating random numbers");  // Printing message

        Random r = new Random();                 // Creating object of class random name "r"
        int [] arr = new int[15];                // Creating array name "arr" of type integer

        for (int i = 0; i < 15; i++)
        {
            arr[i] = r.nextInt(100);            // Generating random number
        }

        Mythr1 thread1 = new Mythr1(arr);            // Creating object of class "Mythr1" name "thread1"
        thread1.start();                             // Calling function "start"

        Mythr2 thread2 = new Mythr2(arr);           // Creating object of class "Mythr2" name "thread1"
        thread2.start();                            // Calling function "start"
    }
}
