def factcal(n):
    if n==0 or n==1:
        return 1
    return n*factcal(n-1)
def factgen(n):
    i=0
    while i<=n:
        yield factcal(i)
        i +=1
g=factgen(4)
for i in g:
    print(i)