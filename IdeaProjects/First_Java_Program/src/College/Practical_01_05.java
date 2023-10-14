package College;

class Practical_01_05
{
    public static int triangle(int n)  // Creating a method name triangle of return type int
    {
        if (n==0)
        {
            return 0;     // returning 0
        }
        return n + triangle(n-1);  // returning value
    };


    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");

        System.out.println("triangle(0) -> "+triangle(0));  // Printing message
        System.out.println("triangle(1) -> "+triangle(1));  // Printing message
        System.out.println("triangle(3) -> "+triangle(3));  // Printing message
    }
}
