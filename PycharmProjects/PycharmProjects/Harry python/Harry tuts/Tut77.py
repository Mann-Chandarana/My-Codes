def searcher():
    import time
    # Some 4seconds are time consuming task
    book = "this is a book on harry and code with harry and good"
    time.sleep(4)

    while True:
        text = (yield )
        if text in book:
            print("Your text in the book")
        else:
            print("Text is not in the book")

search = searcher()
print("search started")
next(search)
print("Next method run")
search.send("harry")
input("press any key")
search.send("harry")

search.close()





