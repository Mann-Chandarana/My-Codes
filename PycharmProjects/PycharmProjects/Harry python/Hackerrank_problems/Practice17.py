from collections import defaultdict
# d = defaultdict(list)
# list1 = []
#
# n,m = map(int,input().split())
#
# for i in range(0,n):
#     d[input()].append(i+1)
#
# for i in range(0,m):
#     list1+=input()
#
# for item in list1:
#     if item in d:
#         print(" ".join(map(str,d[item])))
#
#     else:
#         print(-1)

d = defaultdict(list)
n,m = map(int,input().strip().split())
[d[input().strip()].append(str(a)) for a in range(1,n+1)]
for a in range(m):
    f=input().strip()
    if not d[f]:
        print (-1)
        continue
    print (' '.join(d[f]))