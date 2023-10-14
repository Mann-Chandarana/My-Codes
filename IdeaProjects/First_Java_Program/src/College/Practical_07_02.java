package College;
;
import java.util.*;  // Importing all class

public class Practical_07_02
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        System.out.println("Enter your word");         // Printing message
        Scanner sc = new Scanner(System.in);           // Creating a object name "sc" of class "Scanner"
        String word = sc.nextLine();                   // Taking input from the user


        String []arr = word.split(" ");          // Creating an array name "arr"

        ArrayList<String> list = new ArrayList<String>();      // Creating ArrayList name "list" containing elements of type "String"

        for (String str:arr)
        {
            list.add(str);                              // Adding elements to Arraylist
        }


        TreeSet<String> uniqueSet = new TreeSet<String>(list);    // Creating Treeset name "uniqueSet" containing elements of type "String"


        for (String st:uniqueSet)
        {
            System.out.println(st+":"+ Collections.frequency(list, st));      // Printing message
        }

    }
}
