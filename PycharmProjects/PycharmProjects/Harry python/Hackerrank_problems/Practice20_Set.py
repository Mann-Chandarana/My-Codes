###################### Sets (add)

# n = int(input())
# s = set()
#
# for i in range(0,n):
#     choice = input()
#     s.add(choice)
#
# print(len(s))

###################### Sets (remove,pop and discard)

# n = int(input())
# s = set(map(int,input().split()))
# num = int(input())
# for i in range(num):
#     ip = input().split()
#     if ip[0]=="remove":
#         s.remove(int(ip[1]))
#     elif ip[0]=="discard":
#         s.discard(int(ip[1]))
#     else :
#         s.pop()
# print(sum(list(s)))

###################### Sets (union)

# num1 = int(input())
# set1 = set(map(int,input().split()))
#
# num2 = int(input())
# set2 = set(map(int,input().split()))
#
# new_set = set1.union(set2)
#
# print(len(new_set))


###################### Sets (intersection)
#
# num1 = int(input())
# set1 = set(map(int,input().split()))
#
# num2 = int(input())
# set2 = set(map(int,input().split()))
#
# new_set = set1.intersection(set2)
#
# print(len(new_set))


################## Symmetric Difference

# a,b = (int(input()),input().split())
# c,d = (int(input()),input().split())
#
# x = set(b)
# y = set(d)
#
# p = y.difference(x)
# q = x.difference(y)
# r = p.union(q)
#
# print('\n'.join(sorted(r,key=int)))

################## Difference

# a,b = (int(input()),input().split())
# c,d = (int(input()),input().split())
#
# x = set(b)
# y = set(d)
#
# x = x.difference(y)
#
# print(len(x))

################## Symetric difference operation

a,b = (int(input()),input().split())
c,d = (int(input()),input().split())

x = set(b)
y = set(d)

p = x.symmetric_difference(y)

print(len(p))


