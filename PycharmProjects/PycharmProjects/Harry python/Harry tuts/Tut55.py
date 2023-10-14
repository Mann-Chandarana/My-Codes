class Employee:
    no_of_leaves = 8 ##Template
    pass

harry = Employee()
rohan = Employee()

harry.name = "Harry" #Personal
harry.salary = 455
harry.role = "Instructor"

rohan.name = "Rohan" #Personal
rohan.salary = 4554
rohan.role = "Student"

print(Employee.no_of_leaves)
rohan.no_of_leaves = 9  ##personal - instance variable
print(Employee.no_of_leaves)
print(rohan.__dict__)
print(Employee.__dict__)
