import string

n = int(input())

list_1 = []

while(n):
    values = list(input().split())

    if(values[0]=="insert"):
        list_1.insert(int(values[1]),int(values[2]))

    elif (values[0] == "append"):
        list_1.append(int(values[1]))

    elif (values[0] == "remove"):
        list_1.remove(int(values[1]))

    elif (values[0] == "pop"):
        list_1.pop()

    elif (values[0] == "sort"):
        list_1.sort()

    elif (values[0] == "print"):
        print(list_1)


    elif (values[0] == "reverse"):
        list_1.reverse()

    n -= 1