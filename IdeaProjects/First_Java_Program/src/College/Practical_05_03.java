//Write a program to transfer data from one file to another file so that if the destination file does not exist, it is created.//
package College;

import java.util.*;
import java.io.*;

public class Practical_05_03
{
    public static void main(String args[]) throws IOException
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");

        FileInputStream in = null;
        FileOutputStream ot = null;
        try
        {
            in = new FileInputStream("C:\\Users\\admin\\IdeaProjects\\First_Java_Program\\src\\College\\source.txt");
            ot = new FileOutputStream("C:\\Users\\admin\\IdeaProjects\\First_Java_Program\\src\\College\\destination.txt");
            int c;
            while((c = in.read()) != -1)
            {
                ot.write(c);
            }
        }
        finally
        {
            System.out.println("File content copied in destination file");
            if (in != null)
            {
                in.close();
            }
            if (ot != null)
            {
                ot.close();
            }
        }
    }
}