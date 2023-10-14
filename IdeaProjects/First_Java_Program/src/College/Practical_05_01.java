package College;

import java.io.File;  // importing io.File

class Practical_05_01
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        File f = new File("Mann.txt");          // Creating object name "f" of class "file"
        System.out.println("File name : " + f.getName());    // Printing file name
        System.out.println("Path : " + f.getPath());        // Printing file path
        System.out.println("Absolute path : " + f.getAbsolutePath());  // Printing absolute file path
        System.out.println("Parent : " + f.getParent());        // Printing parent of a file
        System.out.println("Existance of file : " + f.exists());  // Printing true or false is file exists or not

        if (f.exists())
        {
            System.out.println("can we write? : " + f.canWrite());  // Printing can we write or not
            System.out.println("readable? : " + f.canRead());      //  Printing can we read or not
            System.out.println("Is a directory : " + f.isDirectory());  // Printing is directory exists or not
            System.out.println("File Size(bytes) : " + f.length());    // Printing size of file
        }
    }
}
