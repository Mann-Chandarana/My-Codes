package College;

import java.util.*;
import java.io.*;

public class Practical_05_04
{
    public static void main(String args[]) throws IOException
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        FileReader source = null;                     // Creating a object name "source" of class FileReader
        FileInputStream s1 = null;                    // Creating a object name "s1" of class FileInputStream
        FileOutputStream s2 = null;                   // Creating a object name "s2" of class FileInputStream

        try                                                     // Using try block
        {
            source = new FileReader("C:\\Users\\admin\\IdeaProjects\\First_Java_Program\\src\\College\\input.txt");       // Initializing object "source"

            int temp;                                           // Declaring variable "temp" of type int
            while((temp = source.read()) != -1)
            {
                System.out.println((char)temp);                 // Printing message
            }
        }
        finally                                                 // Using "finally" block
        {
            if(source != null)
            {
                source.close();                                  // Closing FileReader
            }
        }
        try                                                     // Using try block
        {
            s1 = new FileInputStream("C:\\Users\\admin\\IdeaProjects\\First_Java_Program\\src\\College\\input.txt");         // Initializing object "s1"
            s2 = new FileOutputStream("C:\\Users\\admin\\IdeaProjects\\First_Java_Program\\src\\College\\output.txt");       // Initializing object "s2"
            int temp;
            while((temp = s1.read()) != -1)
            {
                s2.write((byte)temp);                            // Writing in a file
            }
        }
        finally                                                  // Using "finally" block
        {
            if(s1 != null)
            {
                s1.close();                                      // Closing filestream
            }
            if(s2 != null)
            {
                s2.close();                                      // Closing filestream
            }
        }
    }
}