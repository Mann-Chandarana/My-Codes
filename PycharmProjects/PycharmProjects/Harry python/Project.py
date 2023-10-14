class library:
    def __init__(self,list,name):
        self.bookslist = list
        self.name = name
        self.lendDict = {}

    def displaybook(self):
        print(f"We have following book in our library {self.name}")
        for book in self.bookslist:
            print(book)

    def lenbook(self, user, book):
        if book not in self.lendDict.keys():
            self.lendDict.update({book:user})
            print("Lender-Book database has been updated. You can take book now")
        else:
            print(f"Book is already been issued by {self.lendDict[book]}")

    def addbook(self,book):
        self.bookslist.append(book)
        print("Book has been added to book list")

    def returnbook(self,book):
        self.booksDict.pop(book)

if __name__ == '__main__':
    harry=library(['Python','RichDaddy','Harry Potter','C++ Basics','Algorithm by CLRS'],"Code With harry")

    while (True):
        print(f"Welcome to the {harry.name} library. Enter your choice to continue")
        print("1. Display Books")
        print("2. Lend a Books")
        print("3. Add Books")
        print("4. Remove Books")
        user_choice = int(input())
        # if user_choice not in ['1','2','3','4']:
        #     print("Please enter a valid option")
        #     continue
        # else:
        #     user_choice=int(input())
        if user_choice== 1:
            harry.displaybook()

        elif user_choice== 2:
            book = input("Enter the name of the book you want to lend")
            user=input("Input Enter your name")
            harry.lenbook(user,book)

        elif user_choice== 3:
            book = input("Enter the name of the book you want to add")
            harry.addbook(book)

        elif user_choice== 4:
            book = input("Enter the name of the book you want to return")
            harry.returnbook(book)

        else:
            print("Not a valid option")

        print("Enter q to quit and c to continue")
        user_choice2=input()
        while(user_choice2!="c"and user_choice2!="q"):
            if user_choice2 == "q":
                exit()
            elif user_choice2== "c":
                continue
