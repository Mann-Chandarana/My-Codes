## Solution -1

def findname(num,Borrowers):
    for value in Borrowers:
        if value[0]==num:
            return value[1]

def findbook(num,Books):
    for value in Books:
        if value[0]==num:
            return value[1]

if __name__ =='__main__':
    books=[]
    Borrowers=[]
    Checkouts=[]
    
    s = input()
    dumy = input()

    while(dumy!="Borrowers"):
        dumy = dumy.split('~')
        books.append(dumy)
        dumy = input();
    
    dumy = input()
    
    while (dumy!='Checkouts'):
        dumy = dumy.split('~')
        Borrowers.append(dumy)
        dumy = input()
    
    dumy = input()
    
    while (dumy!='EndOfInput'):
        dumy = dumy.split('~')
        Checkouts.append(dumy)
        dumy = input()

    answer=[]

    for value in Checkouts:
        dumpy=[]
        dumpy.append(value[2])

        name = findname(value[0],Borrowers)
        dumpy.append(name)

        dumpy.append(value[1])

        book = findbook(value[1],books)
        dumpy.append(book)

        answer.append(dumpy)
    
    answer = sorted(answer,key=lambda l:l[2])
    answer = sorted(answer,key=lambda l:l[1])
    answer = sorted(answer,key=lambda l:l[0])

    for element in answer:
        print(element[0]+"~"+element[1]+"~"+element[2]+"~"+element[3])

## Solution -2

def borrowers_input(b):
    z=input()
    while(z!='Checkouts'):
        z=z.split('~')
        b.append(z)
        z=input()  

def checkouts_input(c):
    y=input()
    while(y!='EndOfInput'):
        y=y.split('~')
        c.append(y)
        y=input()

def output():
    name=list()
    Anum=list()
    title=list()
    date=list()
    uname=list()
    
    global books,borrower,checkout
    for a in range(0,len(checkout)):
        date.append(checkout[a][2])

    for b in range(0,len(checkout)):
        uname.append(checkout[b][0])

    for c in range(0,len(uname)):
        for e in range(0,len(borrower)):
            if(uname[c] == borrower[e][0]):
                name.append(borrower[e][1])  

    for a in range(0,len(checkout)):
        Anum.append(checkout[a][1])

    for a in range(0,len(Anum)):
        for b in range(0,len(books)):
            if(Anum[a] == books[b][0]):
                title.append(books[b][1])  

    final=[]
    for i in range(0,len(checkout)):
        final.append(date[i]+'~'+name[i]+'~'+Anum[i]+'~'+title[i])
    final.sort()
    for i in range(0,len(final)):
        print(final[i])



borrower=list()
books=list()
checkout=list()
x=input()
x=input()
while x!='Borrowers':
    x=x.split('~')
    books.append(x)
    x=input()
borrowers_input(borrower)
borrower.sort()
checkouts_input(checkout)
output()  