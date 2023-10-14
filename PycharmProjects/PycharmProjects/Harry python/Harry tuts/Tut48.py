######## Map
#numbers = ["3","34","64"]
# numbers = list(map(int, numbers))
# numbers[2]= numbers[2] + 1
# print(numbers[2])

# for i in range(len(numbers)):
#     numbers[i] = int(numbers[i])

# def sq(a):
#     return a*a
#
# num = [2,3,4,5,6,7]
# square = list(map(sq, num))
# print(square)

# num = [2,3,4,5,6,7]
# square = list(map(lambda x: x*x, num))
# print(square)

# def square(a):
#     return a*a
#
# def cube(a):
#     return a*a*a
#
# func = (square,cube)
# for i in range(5):
#     val = list(map(lambda x:x(i),func))
#     print(val)

######### Filter
# list_1 = (1,2,3,4,5,6)
#
# def is_greater_5(num):
#     return num>5
#
# Mann = list(filter(is_greater_5,list_1))
# print(Mann)

# from functools import reduce
# ######## Reduce
# list1 = [1,2,3,4,5]
# num = reduce(lambda x,y:x+y,list1)
# print(num)

list1 = [1,2,3,4,5]
num = 0
for i in list1:
    num = num + i
print(num)