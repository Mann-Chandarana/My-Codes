######### Name - Mann Chandarana
######### Rollno - 20CS011

from collections import Counter

print("Name :- Mann Chandarana\nRollno :- 20CS011")
n = int(input())

list1 = list(map(int,input().split()))

dic1 = dict(Counter(list1))

for k,v in dic1.items():
    if(v==1):
        print(k)