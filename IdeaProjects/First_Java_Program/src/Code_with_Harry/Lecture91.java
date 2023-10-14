package Code_with_Harry;

import java.util.*;
public class Lecture91 extends Thread
{
    public static void main(String[] args)
    {
        ArrayList<Integer> l1 = new ArrayList<>();
        ArrayList<Integer> l2 = new ArrayList<>(5);
        l1.add(6);
        l1.add(7);
        l1.add(4);
        l1.add(6);
        //l1.add(5);
        l1.add(0,5); // we can add elements in list
        l1.add(0,1);

        l2.add(15);
        l2.add(18);
        l2.add(19);

        l1.addAll(l2); // it will add all the elements of l2 in l1 at end
        l1.addAll(0,l2); // it will add all the elements of l2 in l1 at beginning
        System.out.println(l1.contains(27));
        System.out.println(l1.indexOf(7));
        System.out.println(l1.lastIndexOf(6));
        l1.set(1,566);

        //l1.clear();
        for (int i = 0;i< l1.size();i++)
        {
            System.out.println(l1.get(i)+", ");
        }
    }
}
