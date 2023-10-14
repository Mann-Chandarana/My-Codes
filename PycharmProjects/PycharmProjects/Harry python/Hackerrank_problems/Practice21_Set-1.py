# _ = int(input())
# s1 = set(map(int, input().split()))
# N = int(input())
#
# for _ in range(N):
#     cmd, _ = input().split()
#     s2 = set(map(int, input().split()))
#     if(cmd == "intersection_update"):
#         s1.intersection_update(s2)
#     elif(cmd == "update"):
#         s1.update(s2)
#     elif(cmd == "symmetric_difference_update"):
#         s1.symmetric_difference_update(s2)
#     elif(cmd == "difference_update"):
#         s1.difference_update(s2)
#
# print(sum(s1))

######################## More questions in set

# from collections import Counter
#
# n = int(input())
# list_1 = list(map(int,input().split()))
#
# dic_2 = dict(Counter(list_1))
#
# for k,v in dic_2.items():
#     if(v==1):
#         print(k)

####################### Check subset

# t = int(input())
#
# while(t):
#     n1,set_1 = int(input()),set(map(int,input().split()))
#     n2, set_2 = int(input()), set(map(int, input().split()))
#
#     # if (len(set_1.difference(set_2)) == 0):
#     #     print("True")
#
#     if(set_1.issubset(set_2)):
#         print("True")
#
#     else:
#         print("False")
#     t-=1


######################## Check Strict Superset

set_1 = set(input().split())

n = int(input())

count=0

for i in range(n):
    set_2 = set(input().split())
    if(set_1.issuperset(set_2)):
        count+=1
    else:
        continue

if(count==n):
    print("True")
else:
    print("False")