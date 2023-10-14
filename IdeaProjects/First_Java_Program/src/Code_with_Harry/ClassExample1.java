package Code_with_Harry;

class Employee {
    private int number;  
     int getNumber() {  //accessor method
        return number;  
    }  
     void setNumber(int newNumber) {  //Mutator method
        number = newNumber;  
    }  
}
 class Empmain {  
    public static void main(String args[])
	{
	Employee e1 =new Employee();
	
	e1.setNumber(3);
	System.out.println(e1.getNumber());
	   
	}
}