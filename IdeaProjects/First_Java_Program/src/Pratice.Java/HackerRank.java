package Pratice.Java;

import java.util.Scanner;

public class HackerRank
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int i = 1;
        String a;
        while (sc.hasNext())
        {
            a = sc.nextLine();
            System.out.println(i+" "+a);
            i++;
        }
    }
}
