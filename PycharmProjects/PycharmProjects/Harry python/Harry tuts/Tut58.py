class Employee:
    no_of_leaves = 8 ##Template
    def __init__(self,aname,asalary,arole): ####### Constructor
        self.name = aname
        self.role = arole
        self.salary = asalary

    def printdetails(self):
        return (f"The Name is {self.name}.Salary is {self.salary} and role is {self.role}")

    @classmethod ###########
    def changes_leaves(cls,newleaves):
        cls.no_of_leaves = newleaves

    @classmethod
    def from_str(cls,string):
        #params = string.split("-")
        #return cls(params[0],params[1],params[2])
        return cls(*string.split("-"))



harry = Employee("Harry",455,"Instructor")
rohan = Employee("Rohan",4554,"Student")
karan = Employee.from_str("Karana-480-Student")
print(karan.salary)

# harry.name = "Harry" #Personal
# harry.salary = 455
# harry.role = "Instructor"
#
# rohan.name = "Rohan" #Personal
# rohan.salary = 4554
# rohan.role = "Student"
#print(rohan.printdetails())
#print(harry.salary)
# harry.changes_leaves(34)
#print(harry.no_of_leaves)