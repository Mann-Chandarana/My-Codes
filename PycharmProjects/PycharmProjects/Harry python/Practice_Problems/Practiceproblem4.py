
def next_palidrome(n):
    n = n+1
    while not is_palidrome(n):
        n += 1
    return n


def is_palidrome(n):
    return str(n) == str(n)[::-1]



if __name__ == '__main__':
    n = int(input("Enter the number of test cases\n"))
    numbers = []
    for i in range(n):
        number = int(input("Enter the numbers:\n"))
        numbers.append(number)

    print(numbers)
    for i in range(n):
        print(f"Next palidrome for {numbers[i]} is {next_palidrome(numbers[i])}")



