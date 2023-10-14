# ls = []
# for i in range(100):
#     if i%3 ==0:
#         ls.append(i)
#print(ls)
## Another way

# ls = [i for i in range(100) if i%3==0]
# print(ls)

## Dictionary comprehsion
#dict1 = {i:f"item{i}" for i in range(1,1000) if i%100==0}
# dict1 = {i:f"item{i}" for i in range(5)}
# dict2 = {value:key for key,value in dict1.items()}
# print(dict1,"\n"dict2)

dresses = {dress for dress in ["dress1","dress2","dress1","dress2"]}
#print(type(dresses))
#{} - defines Set operation
#[] - defines list
#() - defines generator
#{},variable- defines Dictionary
## Generator comprehsion
evens = (i for i in range(100) if i%2==0)
# print(type(evens))
# print(evens)
# print(evens.__next__())

for item in evens:
    print(item)