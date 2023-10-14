package College;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Practical_05_05
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        int [] arr = new int[15];                       // Creating array of type integer name "arr"
        Scanner sc = new Scanner(System.in);            // Creating object name "sc" of class Scanner

        System.out.println("Enter fifteen numbers ");        // Printing message
        for (int i = 0; i < 15; i++)
        {
            arr[i] = sc.nextInt();                           // Taking input from the user
        }

        // Creating a file

        File myFile = new File("Even.txt");              // Creating object name "myFile" of class File

        try                                                      // Using try block
        {
            myFile.createNewFile();                             // Creating new file
        }
        catch (IOException o)                                  // Catching error
        {
            System.out.println("Unable to create this file");    // Printing message
            o.printStackTrace();                                 // Using "printStackTrace" function
        }

        // Writing a data to the file

        try                                                           // Using try block
        {
            FileWriter myfile = new FileWriter("Even.txt");    // Creating object name "myfile" of class FileWriter
            for (int element:arr)
            {
                if (element%2==0)
                {
                   myfile.write(Integer.toString(element) + "\n");       // Writing in a file
                }
            }
            myfile.close();                                                // Closing filestream
        }
        catch (IOException e)                                          // Catching error
        {
            e.printStackTrace();                                      // Using method "printStackTrace"
        }


        //Reading from the file

        System.out.println("Your even numbers are");                 // Printing message
        File reading_file = new File("Even.txt");           // Creating object name "reading_file" of class FileWriter

        try                                                        // Using try block
        {
            Scanner Sc = new Scanner(reading_file);                // Creating object name "sc" of class Scanner

            while(Sc.hasNextInt())
            {
                String even_Numbers = Sc.nextLine();         // Creating variable "even_Numbers" and taking input from the user
                System.out.println(even_Numbers);            // Printing message
            }
            Sc.close();                                      // Closing File
        }
        catch (FileNotFoundException e)                       // Catching error
        {
            e.printStackTrace();                              // Using method "printStackTrace"
        }

    }
}
