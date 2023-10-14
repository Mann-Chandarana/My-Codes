package College;
import java.util.*;

class Account    // Creating a class name "Account"
{
    public int id;      // Creating a data member name "id" of return type integer
    public int balance;     // Creating a data member name "balance" of return type integer

    public Account(int i,int b)    // Creating a parameterized constructor
    {
        id = i;
        balance = b;
    }
}
public class Practical_02_03
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        int id,choice,amount=0,Deposit_amt = 0,TId,DId;   // Creating a five data member of return type integer
        int W_Amt = 0;    // Creating a data member of return type integer
        int n = 10;       // Creating a data member of return type integer


        Scanner sc = new Scanner(System.in);  // Creating a object name "sc" of class Scanner
        ArrayList<Account> arr = new ArrayList<>(n);   // Creating a array list name "arr"

        for(int i = 0;i<n;i++)
        {
            arr.add(new Account(i+1,300));    // Adding objects of class Account
        }
        System.out.println("Enter you id");   // Printing the message
        id = sc.nextInt();   // Taking input from the user

        boolean b = false;   // Creating a variable name "b" of type boolean

        while (b!=true)
        {
            for(int i = 0;i<n;i++)
            {
                if (arr.get(i).id == id)
                {
                    b=true;
                    break;
                }
            }
            if (b==true)
            {
                break;
            }
            System.out.println("Incorrect Id! Try again");   // Printing the message
            System.out.println("Enter your id");   // Printing the message
            id = sc.nextInt();  // Taking input from the user
        }

        System.out.println("Enter\n1. for Balance inquiry\n2. for Withdraw money\n3. for Deposit money\n" +
                "4. for Money Transfer\n5. for Create Account\n6. for Deactivate Account\n7. for Exit");  // Printing message

        System.out.println("Enter your choice");  // Printing message
        choice = sc.nextInt();  // Taking input from the user
        while (choice!=7)
        {
            switch (choice)   // Using switch
            {
                case (1) ->
                        {
                            System.out.println(arr.get(id - 1).balance);   // Printing balance
                        }
                case (2) ->
                        {
                            System.out.println("Enter your amount for withdrawal");   // Printing message
                            amount = sc.nextInt();                                    // Taking input from the user
                            if (amount - arr.get(id - 1).balance > 300)
                            {
                                 arr.get(id - 1).balance -= amount;
                                 System.out.println("Withdrawal successfully");    // Printing message
                            }
                            else
                            {
                                System.out.println("Insufficient balance");    // Printing message
                            }
                        }
                case 3 ->
                        {
                            System.out.println("Enter your Amount for Deposit");    // Printing message
                            Deposit_amt = sc.nextInt();                             // Taking input from the user
                            arr.get(id - 1).balance += Deposit_amt;
                        }
                case 4 ->
                        {
                            System.out.println("Enter the id to whom you want to transfer");  // Printing message
                            TId = sc.nextInt();                                               // Taking input from the user
                            if (TId > n)
                            {
                                System.out.println("Invalid Id");        // Printing message
                            }
                            System.out.println("Enter the amount");      // Printing message
                            W_Amt = sc.nextInt();                        // Taking input from the user
                            if (arr.get(id - 1).balance - W_Amt > 300)
                            {
                                arr.get(TId - 1).balance += W_Amt;
                                arr.get(id - 1).balance -= W_Amt;
                            }
                            else
                            {
                                 System.out.println("Insufficient balance");    // Printing message
                            }
                        }
                case 5 ->
                        {
                            String name;                              // Creating a variable of type String
                            System.out.println("Enter your name ");   // Printing message
                            name = sc.next();                         // Taking input from the user
                            n++;
                            arr.add(new Account(n - 1, 300));    // Adding object of class "Account"
                        }
                case 6 ->
                        {
                           System.out.println("Enter the id number which you want to deactivate");  // Printing message
                           DId = sc.nextInt();                                                      // Taking input from the user
                           arr.get(DId - 1).balance = 0;
                           arr.remove(DId - 1);
                           n--;
                        }
                case 7 ->
                        {
                           System.out.println("Exiting . .");       // Printing message
                           System.exit(0);                    // Exiting from the "while" loop
                        }
            }
            System.out.println("Enter your choice");                // Printing message
            choice = sc.nextInt();                                  // Taking input from the user
        }
    }
}

