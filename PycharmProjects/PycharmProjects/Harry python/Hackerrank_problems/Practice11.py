import textwrap

# def wrap(string,max_width):
#         return "\n".join([string[i:i+max_width] for i in range(0,len(string),max_width)])

def wrap(string, max_width):
    return "\n".join(textwrap.wrap(string, max_width))

if __name__ == '__main__':
    str,max_width = input(),int(input())
    result = wrap(str, max_width)
    print(result)