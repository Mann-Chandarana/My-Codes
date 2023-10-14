package College;


class Practical_01_03
{
    public static boolean first_Digit(int a,int b) // Method name first_digit with return type boolean
    {
        char n = Integer.toString(a).charAt(0); // Creating first variable
        char n1 = Integer.toString(b).charAt(0); // Creating second variable
        return (n==n1);   // Returning boolean value
    }

    public static void main(String[] args) // Main method
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        System.out.println("firstDigit(7,71) -> "+first_Digit(7,71));   // Printing message
        System.out.println("firstDigit(6,17) -> "+first_Digit(6,17));   // Printing message
        System.out.println("firstDigit(31,311) -> "+first_Digit(31,311));  // Printing message
    }
}
