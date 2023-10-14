package Pratice.Java;

import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.PatternSyntaxException;

public class Practice5
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.next();
        while (n>0)
        {
            String pattern = sc.nextLine();
            try {
                Pattern.compile(pattern);
                System.out.println("Valid");
            }
            catch (PatternSyntaxException e)
            {
                System.out.println("Invalid");
            }
            n--;
        }
    }
}
