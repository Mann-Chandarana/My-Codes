# def dist(i,j):
    
#     x = abs(dragons[i][0] - dragons[j][0])
#     y = abs(dragons[i][1] - dragons[j][1])
#     return(x+y)

# (rstr,cstr,kstr,dstr) = input().strip().split()

# (r,c,k,d) = (int(rstr),int(cstr),int(kstr),int(dstr))

# dragons = [(0,0)]

# for i in range(d):
#    (xstr,ystr) = input().strip().split()
#    (x,y) = (int(xstr),int(ystr))
#    dragons.append((x,y))

# dragons.sort()

# killed = [[0 for col in range(k+1)] for row in range(d+1)]

# for row in range(d+1):
#    for col in range(k+1):
#       if col != row:
#          killed[row][col] = r*c+1

# for dragon in range(1,d+1):
#    for victim in range(1,min(dragon+1,k+1)):
#        killed[dragon][victim] = min([ killed[i][victim-1] + dist(i,dragon) for i in range(victim-1,dragon) ])

# optimum = min( [ killed[i][k] for i in range(dragon+1) ])
# print(optimum,end="")   
print("Hello")