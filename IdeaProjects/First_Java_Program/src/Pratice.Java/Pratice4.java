package Pratice.Java;


class Thing
{
    public int number_of_things = 0;
    public String what;
    public Thing (String what) {
        this.what = what;
        number_of_things++;
    }
    public void finalize () {
        number_of_things--;
    }
}

public class Pratice4
{
    public static void main(String[] args)
    {
        Thing obj = new Thing("Test App");
    }
}
