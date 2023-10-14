import random

def rohanmultiplcation(number):
    wrong = random.randint(0, 8)
    table = [i * number for i in range(1, 11)]
    table[wrong] = table[wrong] + random.randint(0, 10)
    return table

def is_correct(table,number):
    for i in range(1, 11):
        if table[i-1]!=i*number:
            return i-1

    return None

if __name__ == '__main__':
    #print(rohanmultiplcation(7))
    number = int(input("Enter a number\n"))
    myTable = rohanmultiplcation(number)
    print(myTable)
    wrongIndex = is_correct(myTable,number)
    print(f"The table is wrong at {wrongIndex}")
