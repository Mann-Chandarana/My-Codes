import time
from functools import lru_cache

@lru_cache(maxsize=3)  ## We are saving timeloss by saving it
def some__work(n):
    # Some task taking n secs
    time.sleep(n)
    return n

if __name__ == '__main__':
    print("Now running some work")
    some__work(3)
    some__work(4)
    some__work(1)
    some__work(2)
    print("Done ...Calling again")
    some__work(3)
    print("Called again")