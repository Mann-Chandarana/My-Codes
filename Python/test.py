######################### Assignment -1

######## Question -1

def isprime(n):
    if n==2:
        return True
    
    if n%2==0:
        return False
    
    return all(n%x>0 for x in range(3,int(n**0.5)+1,2))

def genP(n):
    p = [2]
    p.extend([x for x in range(3,n+1,2) if isprime(x)])
    return p

def primepartition(num):
    p = genP(num)
    for i in range(0,len(p)):
        for j in range(0,len(p)):
            if p[i]+p[j]==num:
                return True
    return False

######## Question -2

def matched(s):
    S=s
    current_max = 0
    max = 0
    n = len(S)

    for i in range(0,n):
        if S[i] == '(':
            current_max+=1
            
            if current_max > max:
                max = current_max
        
        elif S[i]==')':
            if current_max > 0:
                current_max-=1
            else:
               return False
    
    if current_max!=0:
        return False

    return True

######## Question -3

def rotatelist(l,k):
    output_list = []

    k = k%len(l)

    for item in range(k,len(l)):
        output_list.append(l[item])

    for item in range(0,k):
        output_list.append(l[item])

    return output_list

list2 = rotatelist([1,2,3,4,5],12)
for x in list2:
    print(x,end=" ")
