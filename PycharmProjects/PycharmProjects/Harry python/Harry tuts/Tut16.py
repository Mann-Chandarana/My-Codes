# list1 = ("Harry","carry")
#
# for item in list1:
#    print(item)

list1 = (["Harry",1,2], ["carry", 2,4])

# for item,lollipop,mango in list1:
#     print(item,lollipop,mango)

dict1 = dict(list1)
print(dict1)
for item, lollypop in dict1.items():
    print(item, "and lolly is ", lollypop)

for item in dict1:
    print(item)

#Quiz
# items = (int,float,"Harry",5, 3, 22, 21, 64, 23, 233, 24)
# for item in items:
#     if str(item).isnumeric() and item>6:
#         print(item)