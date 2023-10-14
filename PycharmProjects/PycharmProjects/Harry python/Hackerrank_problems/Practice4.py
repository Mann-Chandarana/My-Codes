n = int(input())
input_list = list(map(int,input().split()))

input_list.sort()

max = max(input_list)

def not_Equal_to(x):
    return x!=max

input_list = list(filter(not_Equal_to,input_list))

length = len(input_list)

print(input_list[length-1])
