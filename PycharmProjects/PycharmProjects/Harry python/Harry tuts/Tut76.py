try:
    f = open("does2.txt.py")

except Exception as e:
    print(e)

except EOFError as e:
    print("Print eof error aa gaya hai",e)

except IOError as e:
    print("Print IO error aa gaya hai",e)
else:
    print("This will run only if except is not running")

finally: #### It will run the program somhow
    print("Run this anyway")
    #f.close()

print("Important stuff")