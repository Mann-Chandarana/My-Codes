package College;

public class Practical_06_05
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        CubbyHole c = new CubbyHole();                // Creating object name "c" of class "CubbyHole"
        Producer p1 = new Producer(c, 1);     // Creating a object name "p1" of class "Producer"
        Consumer c1 = new Consumer(c, 1);     // Creating a object name "c1" of class "Consumer"
        p1.start();                                  // Calling function "start"
        c1.start();                                  // Calling function "start"
    }
}

class CubbyHole                            // Creating a class name "CubbyHole"
{
    private int contents;                   // Creating a private data member name "contents" of type integer
    private boolean available = false;      // Creating a private data member name "available" of type boolean

    public synchronized int get()           // Creating a method name "get" of return type int
    {
        while (available == false)
        {
            try                              // Using try block
            {
                wait();
            }
            catch (InterruptedException e)       // Using catch block to catch an error
            {
            }
        }
        available = false;
        notifyAll();                     // Using a method name "notifyAll"
        return contents;                 // Returning contents
    }

    public synchronized void put(int value)        // Creating a method name "put" of return type int
    {
        while (available == true)
        {
            try                                   // Using try block
            {
                wait();
            }
            catch (InterruptedException e)         // Using catch block to catch an error
            {
            }
        }
        contents = value;
        available = true;
        notifyAll();
    }
}

class Consumer extends Thread                   // Creating class name "Consumer" extending Thread
{
    private CubbyHole cubbyhole;                // Creating a private variable name "cubbyhole" of type "CubbyHole"
    private int number;                        // Creating a private variable name "number"

    public Consumer(CubbyHole c, int number)    // Creating a parametrized constructor
    {
        cubbyhole = c;
        this.number = number;
    }

    @Override
    public void run()                     // Overriding a function name "run" from super class
    {
        int value = 0;
        for (int i = 1; i < 5; i++)
        {
            value = cubbyhole.get();
            System.out.println("Consumer " + this.number + " got: " + value);    // Printing a message
        }
    }
}

class Producer extends Thread               // Creating class name "Producer" extending Thread
{
    private CubbyHole cubbyhole;            // Creating a private variable name "cubbyhole" of type "CubbyHole"
    private int number;                     // Creating a private variable name "number"

    public Producer(CubbyHole c, int number)     // Creating a parametrized constructor
    {
        cubbyhole = c;
        this.number = number;
    }

    @Override
    public void run()                              // Overriding a function name "run" from super class
    {
        for (int i = 0; i < 10; i++)
        {
            cubbyhole.put(i);
            System.out.println("Producer " + this.number + " put: " + i);
            try                                                // Using try block
            {
                sleep((int) (Math.random() * 100));            // Using "sleep" method
            }
            catch (InterruptedException e)                    // Using catch block catching error
            {
            }
        }
    }
}
