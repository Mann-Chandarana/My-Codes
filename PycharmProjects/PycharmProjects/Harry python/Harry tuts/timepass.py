no_of_list = int(input("How many items add in a list: "))
input_string = input("Enter a list element separated by space ")
list = input_string.split(",")
t = int(input("Which type of comprehension you use 1. List Comprehension 2.Dictionary Comprehension 3. Set Comprehension "))
if t==1:
    ls = [i for i in list]
    print(ls)
    print(type(ls))
elif t==2:
    dict1 = {f'item{i}': i for i in list}
    print(dict1)
    print(type(dict1))
elif t==3:
    s ={i for i in list}
    print(s)
    print(type(s))

###
# n_items = int(input("How many items do you want to add in the list>>"))
# lst = []
# for i in range(1, n_items + 1):
#     items = input(f"Enter the name of {i} item you want to add>>")
#     lst.append(items)
#
# comp = input("Which comprehension you want to make>>(l for ""List"",d for ""Dictionary"",s for ""Set"")")
# if comp == "l":
#
#     print("Here is your list:")
#     print(lst)
#     input()
# elif comp == "d":
#
#     Dict = {i + 1: f"{lst[i]}" for i in range(len(lst.copy()))}
#     print("Here is your dictionary:")
#     print(Dict)
#     input()
# elif comp == "s":
#
#     Set = {items for items in lst}
#     print("Here is your set:")
#     print(Set)
#     input()
# else:
#     print("Incorrect input")
#     input()