package College;

interface  Vehicle  // Creating a interface name "Vehicle"
{
    public String getBrand();  // Declaring function name "getBrand" of return type String
    public String speedUp();  // Declaring function name "speedUp" of return type String
    public String slowDown();  // Declaring function name "slowDown" of return type String
}

class Car implements Vehicle  // Creating a class name "Car" implements "Vehicle"
{
    private String brand;    // Creating a data member name "brand" of return type String

    Car(String a)           // Creating a parameterized constructor
    {
        this.brand=a;
    }

    @Override
    public String getBrand()   // Overridding a method getBrand
    {
        return brand;
    }

    @Override
    public String speedUp()     // Overridding a method speedUp
    {
        return "The car is speeding up.";
    }

    @Override
    public String slowDown()    // Overridding a method slowDown
    {
        return "The car is slowing down.";
    }
}
public class Practical_03_07
{
    public static void main(String[] args)
    {

        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Vehicle car = new Car("Fortuner");  // Creating a object name "car" of class "Vehicle"
        System.out.println(car.getBrand());    // Printing message
        System.out.println(car.speedUp());    // Printing message
        System.out.println(car.slowDown());   // Printing message
        System.out.println("");               // Printing message
    }
}
