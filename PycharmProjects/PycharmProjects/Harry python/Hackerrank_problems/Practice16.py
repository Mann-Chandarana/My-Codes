def average(array):
    arr = set(array)
    length = len(arr)
    sum = 0
    for item in arr:
        sum+=item

    return (sum/length)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)