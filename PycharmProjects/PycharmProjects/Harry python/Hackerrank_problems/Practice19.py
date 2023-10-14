################### namedtuple

# from collections import namedtuple
#
# N = int(input())
# fields = input().strip().split()
# Students = namedtuple('Student',fields)
# total = 0
# r = N
# while(r):
#     field1, field2, field3,field4 = input().split()
#     std = Students(field1,field2,field3,field4)
#     total += int(std.MARKS)
#     r-=1
#
# print('%0.2f'%(total/N))

###################### Ordered dictinary

from collections import OrderedDict
n = int(input())

ordered_dictionary = OrderedDict()

while(n):
    item = input().split(' ')
    price = int(item[-1])
    item_name = " ".join(item[:-1])
    if(ordered_dictionary.get(item_name)):
        ordered_dictionary[item_name]+=price
    else:
        ordered_dictionary[item_name] = price
    n-=1

for key,value in ordered_dictionary.items():
    print(key,value)
