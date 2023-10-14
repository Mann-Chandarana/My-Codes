package Pratice.Java;

class Hel
{
    public static void me()
    {
        System.out.println("Hello I am mann");
    }
}

public class Practice3
{
    static int i = 1;

    static
    {
        System.out.println("Hello "+i);
        Hel.me();
    }

    public static void main(String[] args) {

    }
}
