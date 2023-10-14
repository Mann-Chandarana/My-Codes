# a = int(input())
# b = int(input())
# print(a//b)
# print(a%b)
# print(divmod(a,b))


#################### Power mod power
# a = int(input())
# b = int(input())
# m = int(input())
#
# print(pow(a,b))
# print(pow(a,b,m))

#################### Integer comes in all size


# a = int(input())
# b = int(input())
# c = int(input())
# d = int(input())

# print(pow(a,b)+pow(c,d))

################### Find angle MBC
# import math
# AB,BC=int(input()),int(input())
# hype=math.hypot(AB,BC)                      #to calculate hypotenuse
# res=round(math.degrees(math.acos(BC/hype))) #to calculate required angle
# degree=chr(176)                                #for DEGREE symbol
# print(res,degree, sep='')


################### Triangle Quest

for i in range(1,int(input())):
    print((10**(i)//9)*i)