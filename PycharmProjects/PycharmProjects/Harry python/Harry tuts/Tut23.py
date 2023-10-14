#a = 9
#b = 10
#c = sum((a , b)) #built in function
#print(c)

def function1(a,b):
    """Hello my name is mann"""
    print("You are in function1", a+b)

function1(5,7)

def function2(a,b):
    """This is the function which will calculate average"""
    average = (a+b)/2
    print(average)

def function3(a):
    """Hello Mann here"""
    print(a)

#function2(6,6)
print(function2.__doc__)
print(function1.__doc__)
print(function3.__doc__)


