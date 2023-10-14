d={}
number = int(input())

for i in range(number):
    Name = input()
    Grade = float(input())
    d[Name] = Grade

# v = d.values()
v = []
for key,value in d.items():
    v.append(value)
print(v)


second = sorted(list(set(v)))[1]
second_lowest = []

for key,value in d.items():
    if value== second:
        second_lowest.append(key)

second_lowest.sort()
for item in second_lowest:
    print(item)