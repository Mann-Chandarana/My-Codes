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

    def __add__(self, other):  ###### Special method
        return self.salary + other.salary

    def __truediv__(self, other):  ###### Special method
        return self.salary/other.salary

    def __repr__(self):
        return f"Employee ({self.name},{self.salary},{self.role})"
    def __str__(self):
        return f"The Name is {self.name}.Salary is {self.salary} and role is {self.role}"

emp1 =Employee ("Harry",345 ,"Programmar")
#emp2 =Employee("Rohan",85,"Clearner")
print(emp1)