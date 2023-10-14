package College;

//Author - Mann Chandarana
//Rollno- 20CS011

// (Algebra: linear equations) Design a class named LinearEquation for a
//  system of linear equations:
//  The class contains:
//  ■ Private data fields a, b, c, d, e, and f.
//  ■ A constructor with the arguments for a, b, c, d, e, and f.
//  ■ Six get methods for a, b, c, d, e, and f.
//  ■ A method named isSolvable() that returns true if is not 0.
//  ■ Methods getX() and getY() that return the solution for the equation.
//  Draw the UML diagram for the class and then implement the class. Write a test
//  program that prompts the user to enter a, b, c, d, e, and f and displays the result.
//  If is 0, report that “The equation has no solution.” See Programming

import java.util.Scanner;

class LinearEquation // Class name Linear Equation
{
    private int a,b,c,d,e,f; // Private data-members a,b,c,d,e,f
    LinearEquation(int a,int b,int c,int d,int e,int f)  //  Parameterized constructor
     {
        this.a= a;
        this.b= b;
        this.c= c;
        this.d= d;
        this.e= e;
        this.f= f;
    }

    public int getA()  // Getter method for a
    {
        return a;
    }

    public int getB() // Getter method for b
    {
        return b;
    }

    public int getC() // Getter method for c
    {
        return c;
    }

    public int getD() // Getter method for d
    {
        return d;
    }

    public int getE() // Getter for method e
    {
        return e;
    }

    public int getF() // Getter for method f
    {
        return f;
    }

    boolean isSolvable()  // Member function name isSolvable and return type boolean
    {
        if ((a*d- b*c)!=0)
        {
            return true;
        }
        return false;
    }

    int getX()  // Method to find 1st solution of linear equation
    {
        return (e*d - b*f)/(a*d- b*c);
    }

    int getY()  // Method to find 2nd solution of linear equation
    {
        return (a*f - e*c)/(a*d- b*c);
    }
}

public class College_Pratical
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);  // Scanner class object name sc
        System.out.println("Enter a,b,c,d,e,f");
        int a,b,c,d,e,f; // variable name a,b,c,d,e,f
        a=sc.nextInt();b=sc.nextInt();c=sc.nextInt();d= sc.nextInt();e= sc.nextInt();;f= sc.nextInt(); // Taking input from the user
        LinearEquation Q = new LinearEquation(a,b,c,d,e,f);  // Object of class linearequation name Q
        if (Q.isSolvable())
        {
            System.out.println("Solution for x is "+Q.getX());  // Printing output of 1st solution
            System.out.println("Solution for y is "+Q.getY());  // Printing output of 2nd solution
        }
        else
        {
            System.out.println("The equation has no solution.");  // Printing output when solution does'nt exists
        }
    }
}
