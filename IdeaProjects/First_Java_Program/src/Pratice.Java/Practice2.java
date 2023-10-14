package Pratice.Java;

import java.util.Scanner;

class NegativeNumbers extends Exception
{
    void message()
    {
        System.out.println("Negative numbers are not allowed");
    }
}
public class Practice2
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        if (a<0)
        {
            try {
                throw new NegativeNumbers();
            }
            catch (NegativeNumbers e)
            {
                e.message();
            }
        }

    }
}
