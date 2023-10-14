package College;

public class Practical_01_04
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");

        char [][]marks = new char[][]          // Creating 2-D Array name marks of type char
                {
                        {'A','B','A','C','C','D','E','E','A','D'},
                        {'D','B','A','B','C','A','E','E','A','D'},
                        {'E','D','D','A','C','B','E','E','A','D'},
                        {'C','B','A','E','D','C','E','E','A','D'},
                        {'A','B','D','C','C','D','E','E','A','D'},
                        {'B','B','E','C','C','D','E','E','A','D'},
                        {'B','B','A','C','C','D','E','E','A','D'},
                        {'E','B','E','C','C','D','E','E','A','D'},
                };


        char []key = new char[]               // Creating 1-D Array name key of type char
                {'D','B','D','C','C','D','A','E','A','D'};

        int []result = new int[8];           // Creating 1-D Array name result of type int

        for (int i = 0;i<8;i++)             // Using For-loop
        {
            for (int j = 0;j<10;j++)        // Using For-loop
            {
                if (marks[i][j]==key[j])
                {
                    result[i]++;
                }
            }
        }
        for (int i = 0;i<8;i++)             // Using For-loop
        {
            System.out.println("Result of student "+(i+1)+" is "+ result[i] + "/10");   // Printing message
        }
    }
}
