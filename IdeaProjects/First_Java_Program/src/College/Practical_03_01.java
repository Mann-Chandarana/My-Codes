package College;

abstract class Geometric_Object  // Creating a abstract class name "Geometric_Object"
{
    public String color = "white";  // Creating a data member name "color" of return type "String"
    public boolean filled;         // Creating a data member name "filled" of return type "boolean"
    public java.util.Date datecreated;

    protected Geometric_Object()  // Creating default constructor
    {
        datecreated = new java.util.Date();
    }
    Geometric_Object(String color,boolean filled)  // Creating a parametrized constructor
    {
        this.color = color;
        this.filled = filled;
    }
    public String getcolor()  // Creating a member function name "getcolor" of return type String
    {
        return color;
    }
    public void setColor(String color)  // Creating a member function name "setcolor"
    {
        this.color = color;
    }
    public boolean isfilled()  // Creating a member function name "isfilled" of return type boolean
    {
        return filled;
    }
    public java.util.Date getDateCreated()
    {
        return datecreated;
    }

    public abstract double get_Area();   // Creating a abstract method name "get_Area" of return type double

    public abstract double get_perimeter();   // Creating a abstract method name "get_perimeter" of return type double
}

class Rectangle extends Geometric_Object  // Creating a class name "Rectangle" extending "Geometric_Object"
{
    public double width;   // Creating a data member name "width" of return type double
    public double height; // Creating a data member name "height" of return type double

    Rectangle()   // Creating default constructor
    {};
    Rectangle(double width,double height)  // Creating a parametrized constructor
    {
        this.width = width;
        this.height = height;
    }
    Rectangle(double width,double height,String color,boolean filled)  // Creating a parametrized constructor
    {
        super(color,filled);
        this.width = width;
        this.height = height;
    }
    public double getWidth()     // Creating a getter for width
    {
        return width;
    }
    public double getheight()     // Creating a getter for height
    {
        return height;
    }
    public void setWidth(double width)     // Creating a getter for width
    {
        this.width = width;
    }
    public void setHeight(double height)   // Creating a setter name "setHeight" for setting value of "Height"
    {
        this.height = height;
    }
    public double get_Area()   // Creating a member function name "get_Area" of return type double for calculating area
    {
        return height*width;
    }
    public double get_perimeter()  // Creating a member function name "get_Perimeter" of return type double for calculating perimeter
    {
        return 2*(width+height);
    }
}

class Circle extends Geometric_Object  // Creating a class name "Circle" extending "Geometric_Object"
{
    public double radius;   // Creating a data member name "radius" of return type double

    Circle(){}             // Creating default constructor

    Circle(double radius)    // Creating a parametrized constructor
    {
        this.radius = radius;
    }

    public double getRadius()   // Creating a getter for radius
    {
        return radius;
    }
    public void setRadius(double radius)   // Creating a setter name "setRadius" for setting value of radius
    {
        this.radius = radius;
    }
    public double getDiameter()   // Creating a getter for diameter
    {
        return 2 * radius;
    }
    public double get_Area()   // Creatng a member function name "get_Area" for calculating area of return type double
    {
        return Math.PI * radius*radius;
    }
    public double get_perimeter()  // Creatng a member function name "get_perimeter" for calculating perimeter of return type double
    {
        return 2 * radius * Math.PI;
    }

}
public class Practical_03_01
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Rectangle Rec = new Rectangle(10,15);  // Creating object name "Rec" of class Rectangle
        Circle cir = new Circle(15);                // Creating object name "Circle" of class Circle
        System.out.println("Class Circle");              // Printing message
        System.out.println("Area "+ cir.get_Area());     // Printing area
        System.out.println("Perimeter "+cir.get_perimeter());   // Printing perimeter
        System.out.println("Diameter "+ cir.getDiameter()+"\n");     // Printing Diameter

        System.out.println("*************************************************************************************\n");

        System.out.println("Class Rectangle");         // Printing message
        System.out.println("Area "+ Rec.get_Area());   // Printing area
        System.out.println("Perimeter "+Rec.get_perimeter());  // Printing Perimeter
    }
}