package Code_with_Harry;

import  java.util.Scanner;

public class Practice_set_Ch2
{
    public static void main(String[] args)
    {
        ///////////// Question-01

        float a = 7/4.0f * 9/2.0f;
        System.out.println(a);

        ///////////// Question-02
        char grade = 'B';
        grade = (char)(grade + 8);
        System.out.println(grade);
        // Decrypting the grade
        grade = (char)(grade - 8);
        System.out.println(grade);

        ///////////// Question-03
        Scanner sc = new Scanner(System.in);
        int b = sc.nextInt();
        System.out.println(b>8);
        System.out.println(7*49/7+35/7);
    }
}
