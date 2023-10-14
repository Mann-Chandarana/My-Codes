class Employee:
    no_of_leaves = 8 ##Template
    def __init__(self,aname,asalary,arole): ####### Constructor
        self.name = aname
        self.role = arole
        self.salary = asalary

    def printdetails(self):
        return (f"Name is {self.name}.Salary is {self.salary} and role is {self.role}")


harry = Employee("Harry",455,"Instructor")
# rohan = Employee()

# harry.name = "Harry" #Personal
# harry.salary = 455
# harry.role = "Instructor"
#
# rohan.name = "Rohan" #Personal
# rohan.salary = 4554
# rohan.role = "Student"


print(harry.salary)
#print(rohan.printdetails())