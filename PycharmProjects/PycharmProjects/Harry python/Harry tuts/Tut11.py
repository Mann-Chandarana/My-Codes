s = set()
print(type(s))
s = set([1,2,3])
print(s)
s.remove(2)
print(s)
s.add(1)
print(s)
s1 = s.union({1,2,3})
print(s,s1)
#s2 = s.isdisjoint(s1)
#print(s2)
s2 = s.intersection(s1)
print(s2)