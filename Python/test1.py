def remdup(l):
    set_1 = set()

    for i in range(len(l)-1,-1,-1):
        if l[i] in set_1:
            del l[i]
        else:
          set_1.add(l[i])

    return l


def splitsum(l):
    test=[0,0]
    for x in l:
        if x>=0:
            test[0]+=(x*x)
        else:
            test[1]+=(x*x*x)

    return test


def matrixflip(m,d):
    H=[]
    if d=='h':
        for r in m:
            hr=[]
            print(r)
            for row in range(1,len(r)+1):
                hr.append(r[-row])
            H.append(hr)
        return (H)
    
    if d=='v':
        V=[]
        for vr in range(1,len(m)+1):
            V.append(m[-vr])
        return (V)