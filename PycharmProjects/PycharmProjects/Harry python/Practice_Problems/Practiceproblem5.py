def next_palidrome(n):
    n = n+1
    while not is_palidrome(n):
        n += 1
    return n


def is_palidrome(n):
    return str(n) == str(n)[::-1]

if __name__ == '__main__':
    size = int(input("Enter the size of the list\n"))
    num_list=[]
    for i in range(size):
        num_list.append(int(input("Enter the number for list\n")))
    print(f"You have entered {num_list}")
    print(f"Output list: {[num_list[i] if num_list[i] < 10 else next_palidrome(num_list[i]) for i in range(size)]}")

    # new_list = []
    # for element in num_list:
    #     if element>10:
    #         n = next_palidrome(element)
    #         new_list.append(n)
    #     else:
    #         new_list.append(element)
    # print(f"Output list :{new_list}")


