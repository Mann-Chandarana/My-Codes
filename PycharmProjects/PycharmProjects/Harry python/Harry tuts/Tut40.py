# def function_name_print(a, b, c, d, e ):
#     print(a, b, c, d, e)
#
# function_name_print("Harry", "Rohan", "Skillf", "Hammad", "Shivam")

# def funargs(*args):
#     for item in args:
#         print(item)
#
# har = ("Harry", "Rohan", "Skillf", "Shivam")
# funargs(har)

# def funargs(normal,*args,**kwargs):
#     print(normal)
#     for item in args:
#          print(item)
#     print("\n Now i would Like to introduce some of our heroes")
#     for key,value in kwargs.items():
#         print(f"(key) is a (value)")
#
#
#
# har = ("Harry", "Rohan", "Skillf", "Shivam")
# normal = "this is a normal"
# kw = ("Rohan":"Monitor", "Mann":"Cook")
# funargs(normal, *har, ** kw)