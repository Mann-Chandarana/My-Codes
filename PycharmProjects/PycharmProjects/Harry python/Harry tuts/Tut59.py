class Employee:
    no_of_leaves = 8 ##Template
    def __init__(self,aname,asalary,arole): ####### Constructor
        self.name = aname
        self.role = arole
        self.salary = asalary

    def printdetails(self):
        return (f"The Name is {self.name}.Salary is {self.salary} and role is {self.role}")

    @classmethod  ###########
    def changes_leaves(cls,newleaves):
        cls.no_of_leaves = newleaves

    @classmethod ### Takes class as a parameter
    def from_str(cls,string):
        #params = string.split("-")0

        #return cls(params[0],params[1],params[2])
        return cls(*string.split("-"))

    @staticmethod ### No Parameter is required
    def printgood(string):
        print("This is Good " + string)

karan = Employee.from_str("Karana-480-Student")
# print(karan.salary)
karan.printgood("Harry")
