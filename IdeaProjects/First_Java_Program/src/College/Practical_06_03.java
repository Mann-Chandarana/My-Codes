package College;

class Mythread extends Thread          // Creating class name "Mythread" extending Thread
{
    int count = 0;                    // Creating a variable name "count" of type integer

    @Override
    public void run()                                 // Overriding method "run" of super class
    {
        int i = 0;
        while (i<10)
        {
            System.out.println(count);                // Printing message

            try                                       // Using try block
            {
                Mythread.sleep(1000);            // Using method "sleep"
            }
            catch (Exception e)                      // Using catch block
            {
                e.printStackTrace();                 // Using method "printStackTrace"
            }
            count++;
            i++;
        }
    }
}

public class Practical_06_03
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");

        System.out.println("Using sleep of 1 sec");   // Printing message
        Mythread t1 = new Mythread();                 // Creating object of class "Mythread" name "t1"
        t1.start();                                   // Calling function "start"
    }
}
