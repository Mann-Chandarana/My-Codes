package Code_with_Harry;// Java program to demonstrate the
// working of ArrayList in Java

import java.io.*;
import java.util.*;

class ArrayListExample {
	public static void main(String[] args)
	{
		// Size of the
		// ArrayList
		int n = 5;

		// Declaring the ArrayList with
		// initial size n
		ArrayList<Integer> arrli= new ArrayList<Integer>(n);

		// Appending new elements at
		// the end of the list
		for (int i = 1; i <= n; i++)
			arrli.add(i);
			
			
for (int i = 0; i < arrli.size(); i++)
			System.out.print(arrli.get(i) + " ");
			
		System.out.println();
		
		System.out.println("Printing elements");
		//System.out.println(arrli);
		
		arrli.add(6);
		arrli.add(7);
		arrli.add(8);
		
		for (int i = 0; i < arrli.size(); i++)
			System.out.print(arrli.get(i) + " ");
			
          System.out.println();
		 System.out.println("After Removing element at index 3");
	
		  arrli.remove(3);

		
		//System.out.println(arrli);

		// Printing elements one by one
		for (int i = 0; i < arrli.size(); i++)
			System.out.print(arrli.get(i) + " "); 
	}
}
