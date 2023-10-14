package College;

// (Sum elements column by column) Write a method that returns the sum of all the
//  elements in a specified column in a matrix using the following header:
//  public static double sumColumn(double[][] m, int columnIndex)
//  Write a test program that reads a 3-by-4 matrix and displays the sum of each column. Here is a sample run:


import java.util.Scanner;

public class College_practical1
{
    public static void main(String[] args)
    {
        int [][] arr = new int[3][4];
        Scanner sc = new Scanner(System.in);
        int input;
        for (int i = 0; i < 3 ; i++)
        {
            for (int j = 0; j < 4 ; j++)
            {
                System.out.println("Enter number of index arr"+"["+i+"]"+"["+j+"]");
                input = sc.nextInt();
                arr[i][j] =  input;
            }
        }

        int [] sum = new int[3];

        for (int i = 0; i <3; i++)
        {
            sum[i] = arr[i][0]+ arr[i][1]+arr[i][2]+arr[i][3];
        }

        for (int i = 0; i < 3; i++)
        {
            System.out.println("Sum of column "+(i+1)+ " is "+sum[i]);
        }
    }
}
