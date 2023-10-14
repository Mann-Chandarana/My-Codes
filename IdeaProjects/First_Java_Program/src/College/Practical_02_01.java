package College;

class Cylinder   // Creating a class name Cylinder
{
    public int radius = 1;   // Creating a public data member name radius
    public int height = 1;   // Creating a public data member name height

    public Cylinder()   // Creating a default constructor
    {
        radius = 0;
        height = 0;
    }
    public Cylinder(int radius)  // Creating a parametrized constructor
    {
        this.radius = radius;
    }

    public Cylinder(int radius,int height)  // Creating a parametrized constructor
    {
        this.radius = radius;
        this.height = height;
    }
    public double get_Area()   // Creating a method name get_area with return type double, which will calculate area of a Cylinder
    {
        double area = (2*3.14*radius*height)+(2*3.14*radius*radius);
        return  area;             // Returning area
    }

}
public class Practical_02_01
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Cylinder obj1 = new Cylinder(5,13);   // Creating a object name obj1 of class Cylinder
        double area = obj1.get_Area();   // Creating a variable name area
        System.out.println("Printing Area of a cylinder");  // Printing message
        System.out.println(area);   // Printing area of a cylinder
    }
}
