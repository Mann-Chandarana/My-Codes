print("Enter the numbers of the list one by one")
size = int(input("Enter the size of list\n"))
mylist = []
for i in range(size):
    mylist.append(int(input("Enter the list element\n")))

print(f"Your list is {mylist}")
reverse1=mylist[:]
reverse1.reverse()
reverse2=mylist[::-1]
print(f"My First reversed list of {mylist} is {reverse1}")
print(f"My Second reversed list of {mylist} is {reverse2}")
reverse3=mylist[:]

for i in range(len(mylist)//2):
    reverse3[i],reverse3[len(mylist)-i-1]=reverse3[len(mylist)-i-1],reverse3[i]

print(f"My Third reversed list of {mylist} is {reverse3}")
if reverse1==reverse2 and reverse2== reverse3:
    print("All three gave same result")