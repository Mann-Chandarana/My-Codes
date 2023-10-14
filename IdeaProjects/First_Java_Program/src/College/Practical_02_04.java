package College;

class creating_account extends acount    // Creating a class name "creating_account" extending a class "account" from program 02
{
    public void checking(int i,acount obj)   // Creating a method name "checking"
    {
        int overdraft = -1000;         // Creating a data member name "overdraft" of return type integer

        if (obj.balance -i < overdraft)
        {
            System.out.println("Failure: Can't overdraft more than 1,000.\n");   // Printing message
        }
        else
        {
            obj.balance-= i ;
            System.out.println("Id is "+obj.getId());
            System.out.println("Your balance is "+obj.getBalance()+"\n");
        }
    }
}

class Saving_Account extends acount   // Creating a class name "Saving_account" extending a class "account" from program 02
{
    public void withDraw(int w,acount obj)    // Creating a method name "withDraw"
    {
        int overdraft = 0;                    // Creating a data member name "overdraft" of return type integer
        if (obj.getBalance() -w < overdraft)
        {
            System.out.println("Insufficient Funds\n");    // Printing message
        }
        else
        {
            obj.balance= obj.balance - w;
            System.out.println("Successful withdrawal\n");
        }
    }
}

public class Practical_02_04
{
    public static void main(String[] args)
    {
        /////////////////////////// Introduction/////////////////////////////////

        System.out.println("*****************************");
        System.out.println("\tName: Mann Chandarana");
        System.out.println("\tID: 20CS011");
        System.out.println("*****************************\n");


        acount myaccount = new acount(45,25000,0.07);  // Creating a object name "myaccount" of class "account"
        Saving_Account saving_account = new Saving_Account();       // Creating a object name "saving_account" of class "Saving_Account"
        saving_account.withDraw(2000,myaccount);                // Using member function "withDraw"
        creating_account c1 = new creating_account();             // Creating a object name "c1" of class "creating_account"
//        c1.checking(24000,myaccount);                          // Using member function "checking"
        c1.checking(2000,myaccount);                         // Using member function "checking"
    }
}
