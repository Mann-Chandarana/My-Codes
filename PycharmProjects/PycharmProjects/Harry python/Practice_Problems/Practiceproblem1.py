yearAge = int(input("What is your age/Year of birth\n"))
isAge = False
isYear = False


if(len(str(yearAge))==4):
    isYear = True

else:
    isAge = True



if(yearAge<1900 and isYear):
    print("You seems to be oldest person on the planet")
    exit()

if(yearAge>2019):
    print("You are not yet born")
    exit()


if isAge:
    yearAge=2021-yearAge

print(f"You will be 100 years old in {yearAge+100}")
intersetedyear=int(input())
print(f"You will be {intersetedyear-yearAge} year old in {intersetedyear}")