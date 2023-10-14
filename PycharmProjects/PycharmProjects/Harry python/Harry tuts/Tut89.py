# a = input("What is your name")
# b = input("How much do you earn")
# if int(b)==0:
#     raise ZeroDivisionError("B is 0 stooping program")
# if a.isnumeric():
#     raise Exception("numbers are not allowed")
#
# print(f"Hello {a}")
# Task - Write about 2 built in exception

c = input("Enter your name")
try:
    print(b)

except Exception as e:

    if c == "Mann":
        raise ValueError("Mann is blocked he is not allowed")

    print("Exception handled")
