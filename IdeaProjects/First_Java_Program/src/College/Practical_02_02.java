package College;

import java.util.Date;   // Importing Date class

class acount  // Creating a class name account
{
    private int id;  // Creating a private data member of type integer
    public double balance,Interest_Rate;  // Creating two data member of type double
    private Date dateCreated;   // Creating a private data member of type Date

    acount()  // Creating a default constructor
    {
        id = 0;
        balance = 0;
        Interest_Rate = 0.07;
    }

    acount(int id,int balance,double Ir)  // Creating a parameterized constructor
    {
        this.id = id;
        this.balance = balance;
        Interest_Rate = Ir;
    }

    public int getId()    // Creating a getter of return type int
    {
        return id;
    }

    public void setId(int id)     // Creating a setter, setting the value of id
    {
        this.id = id;
    }

    public double getBalance()    // Creating a getter of return double
    {
        return balance;
    }

    public void setBalance(double balance)   // Creating a setter, setting the value of balance
    {
        this.balance = balance;
    }

    public double getInterest_Rate()  // Creating a getter of return double
    {
        return Interest_Rate;
    }

    public void setInterest_Rate(double interest_Rate)   // Creating a setter, setting the value of Interest_rate
{
        Interest_Rate = interest_Rate;
    }

    public Date getDateCreated()
    {
        return dateCreated;
    }

    public double getMonthlyInterestRate()   // Creating a method for calculating monthly interest rate of return type double
    {
        return (Interest_Rate/12);
    }

    public double getMonthlyInterest()    // Creating a method for calculating monthly interest of return type double
    {
        return (balance*(Interest_Rate/12));
    }

    public void WithDraw(int amount)  // Creating a method for withdrawal process
    {
        balance -= amount;
    }

    public void Deposit(int amt)    // Creating a method for money deposit
    {
        balance+=amt;
    }
}
public class Practical_02_02
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        acount myaccount = new acount(45,25000,0.07);  // Creating a object name myaccount of class account
        myaccount.WithDraw(5000);   // Using member function WithDraw
        myaccount.Deposit(2000);    // Using member function Deposit

        System.out.println("Your balance is "+myaccount.getBalance());     // Printing balance
        System.out.println("Monthly Interest: " + myaccount.getMonthlyInterestRate());   // Printing monthly interest

        Date created = new Date();  // Creating a object of class Date
        System.out.println("Your account was created on "+created);   // Printing the date of creation of the account
    }
}
