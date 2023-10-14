# from itertools import product
#
# a = list(map(int,input().split()))
# b = list(map(int,input().split()))
#
# print(*product(a,b))

# from itertools import permutations
#
# word,num = input().split()
# permutations = list(permutations(word,int(num)))
# permutations.sort()
#
# for i in permutations:
#     print("".join(i))

###### cmath polar

import cmath
r = complex(input().strip())
print(cmath.polar(r)[0])
print(cmath.polar(r)[1])