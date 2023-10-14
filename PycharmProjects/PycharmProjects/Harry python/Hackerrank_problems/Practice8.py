def mutate_string(string, position, character):
    new_string = string[0:position]+character+string[position+1:]
    return new_string

if __name__ == '__main__':
    string = input()
    i,c = input().split()
    s = mutate_string(string,int(i),c)
    print(s)


