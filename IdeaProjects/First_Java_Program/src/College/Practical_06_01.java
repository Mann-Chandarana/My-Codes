package College;

class Thread1 extends Thread       // Creating class name "Thread1" extending Thread
{
    @Override
    public void run()             // Overriding method "run" of super class
    {
        int i = 0;
        while (i<10)
        {
            System.out.println("I am Thread 1");       // Printing message
            i++;
        }
    }
}

class  Thread2 implements Runnable         // Creating class name "Thread2" and implementing Runnable interface
{
    @Override
    public void run()               // Overriding method "run" of super class
    {
        int i = 0;
        while (i<10)
        {
            System.out.println("I am Thread 2");      // Printing message
            i++;
        }
    }
}

public class Practical_06_01
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Thread1 t1 = new Thread1();         // Creating object of thread1 class name "t1"
        Thread2 t2 = new Thread2();         // Creating object of thread2 class name "t2"

        Thread t = new Thread(t2);         // Creating object of thread class name "t"

        t1.start();                       // Calling function "start"
        t.start();                        // Calling function "start"
    }
}
