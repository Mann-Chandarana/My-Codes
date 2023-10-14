package Pratice.Java;

import java.util.Locale;
import java.util.Scanner;

public class HackerRank2
{
    public static void main(String[] args)
    {
        Scanner SC = new Scanner(System.in);
        String A;
        String B;
        A = SC.next();
        B = SC.next();

        System.out.println(A.length()+B.length());
        System.out.println(A.compareTo(B)>0?"Yes":"No");
        System.out.println(A.substring(0,1).toUpperCase()+A.substring(1,A.length())+" "+B.substring(0,1).toUpperCase()+B.substring(1,B.length()));
    }
}
