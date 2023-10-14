from collections import Counter

x = int(input())
list1 = list(map(int,input().split()))

n = int(input())
sum = 0

dic1 = Counter(list1)

for i in range(n):
    size,x = map(int,input().split())
    if(dic1[size]!=0):
        dic1[size]-=1
        sum+=x
    else:
        continue

print(sum)