#print("Enter number 1")
#num1 = int(input())
#print("Enter number 2")
#num2 = int(input())
#print("the sum of this two number is", num1-num2)

print("Enter number 1")
num1 = input()
print("Enter number 2")
num2 = input()
try:
    print("the sum of this two number is",
          int(num1)+int(num2))
except Exception as e:
    print(e)
