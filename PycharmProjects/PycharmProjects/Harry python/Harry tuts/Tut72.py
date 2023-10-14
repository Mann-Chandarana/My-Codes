"""
Iterable - __iter__() or __getitem__()
Ierator - __next__()
Iterable -
"""
# Generator is one type of Iterator Which can be traverse only one time

# for i in range(78):
#     print(i)

# def mann(n):
#     for i in range(n):
#         yield i   ##### Generator
#
# g = mann(3)
# print(g.__next__())
# print(g.__next__())
# print(g.__next__())

# for i in g:
#     print(i)

h ="harry"
ier = iter(h)
print(ier.__next__())
print(ier.__next__())
# for c in h:
#     print(c)
