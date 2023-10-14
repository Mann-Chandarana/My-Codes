class Employee:
    var = 8
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

class player:
    var = 9
    no_of_games = 4
    def __init__(self,name,game):
        self.name = name
        self.game = game

    def printdetails(self):
        return (f"The Name is {self.name}.game is {self.game}")

class coolProgrammar(Employee,player):
    var = 10
    language = "C++"
    def printlanguage(self):
        print(self.language)

harry = Employee("Harry",455,"Instructor")
rohan = Employee("Rohan",4554,"Student")

Shumbham = player("Shubham",["Cricket"])
karan = coolProgrammar("karan",8999,"coolProgrammar")
# det = karan.printdetails()
# karan.printlanguage()
# print(det)
print(karan.var)