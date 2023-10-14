package Pratice.Java;

import java.util.Scanner;

public class HackerRank4
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        boolean b = true;
        for (int i = 0; i < a.length()/2; i++)
        {
            if (a.charAt(i) != a.charAt(a.length()-1-i))
            {
                b = false;
            }
        }
        if (b) {
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }

    }
}
