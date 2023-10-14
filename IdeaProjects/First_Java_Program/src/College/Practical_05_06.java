package College;

class Wraper
{
    public static void main(String args[])
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        //Converting int into Integer
        int a = 15;                          // Creating variable name "a" of type int
        Integer i = Integer.valueOf(a);      //converting int into Integer explicitly
        Integer j = a;                       //autoboxing, now compiler will write Integer.valueOf(a) internally
        System.out.println(a + " " + i + " " + j);   // Printing message
    }
}