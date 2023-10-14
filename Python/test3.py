###### Week - 4

###### Assignement - 1

def rainaverage(list_l):
    count = {}
    dict_1={}
    for i, j in list_l:
        if i not in count.keys():
            count[i] = 1
            dict_1[i] = j
        else:
            count[i] = count[i]+1
            dict_1[i] = dict_1[i]+j

    for i in count:
        dict_1[i] = dict_1[i]/count[i]
    
    l2 = [(i,j) for i,j in dict_1.items()]
    l2.sort(key=lambda a:a[0])
    
    return l2

###### Assignement - 2

def listtype(l):
  return(type(l) == type([]))


l3=[]

def flatten(l4):
    for i in l4:
        if listtype(i):
            flatten(i)
        else:
            l3.append(i)

    return l3

l = flatten([1,2,3,(4,5,6)])

for i in l:
    print(i)
        