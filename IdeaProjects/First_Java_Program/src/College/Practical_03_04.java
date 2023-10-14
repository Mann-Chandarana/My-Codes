package College;

class Human   // Creating a class name "Human"
{
    public void eat()  // Creating a member function name "eat"
    {
        System.out.println("Human is eating\n");  // Printing message
    }
}


class Boy extends Human  // Creating a class name "Boy" extends class name "Human"
{
    @Override
    public void eat()   // Overidding a method name "eat" of super class
    {
        System.out.println("Boy is eating\n");  // Printing message
    }

    public static void main(String args[])
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        Human ob = new Human(); // Creating a object name "ob" of class "Human"
        ob.eat();    // Calling a member function "eat"

        Boy obj = new Boy(); // Creating a object name "obj" of class "Boy"
        obj.eat();  // Calling a member function "eat"
    }
}
