package College;

// (Count occurrence of numbers) Write a program that reads the integers between 1
//  and 100 and counts the occurrences of each. Assume the input ends with 0. Here is
//  a sample run of the program:


import java.util.Scanner;

public class College_practical
{
    public static void check_Occurence(int []arr)
    {
        int []check = new int [100];

        for (int i = 0; i < 100; i++)
        {
            if (arr[i]!=0)
            {
                check[arr[i]] += 1;
            }
        }
        for (int i = 0; i < 100 ; i++)
        {
            if (arr[i]!=0 && check[arr[i]]!=0)
            {
                System.out.println(arr[i]+" occur "+check[arr[i]]+" times");
                check[arr[i]] = 0;
            }
        }
    }
    public static void main(String[] args)
    {
        int []arr = new int[100];
        int i=0,input;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number between 1 to 100");
        do
        {
            input = sc.nextInt();
            arr[i] = input;
            i++;
        }
        while (input!=0);

        check_Occurence(arr);
    }
}
