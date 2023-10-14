package College;

class First extends Thread                           // Creating class name "First" extending Thread
{
    @Override
    public void run()                                      // Overriding method "run" of super class
    {
        int i = 0;
        while (i<10)
        {
            System.out.println("Running Thread-1");          // Printing message
            i++;
        }
    }
}


class Second extends Thread                          // Creating class name "Second" extending Thread
{
    @Override
    public void run()                                   // Overriding method "run" of super class
    {
        int i = 0;
        while (i<10)
        {
            System.out.println("Running Thread-2");           // Printing message
            i++;
        }
    }
}


class Third extends Thread                         // Creating class name "Third" extending Thread
{
    @Override
    public void run()                                    // Overriding method "run" of super class
    {
        int i = 0;
        while (i<10)
        {
            System.out.println("Running Thread-3");         // Printing message
            i++;
        }
    }
}

public class Practical_06_04
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        First t1 = new First();                   // Creating object name "t1" of class "First"
        Second t2 = new Second();                 // Creating object name "t2" of class "Second"
        Third t3 = new Third();                    // Creating object name "t3" of class "Third"

        t1.setPriority(3);                      // Setting priority of first thread
        t2.setPriority(5);                      // Setting priority of Second thread
        t3.setPriority(7);                     // Setting priority of Third thread

        t1.start();                            // Calling function "start"
        t2.start();                            // Calling function "start"
        t3.start();                            // Calling function "start"
    }
}
