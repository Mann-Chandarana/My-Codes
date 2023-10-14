class Dad:
    basketball = 6

class son(Dad):
    dance = 1
    basketball = 9
    def isdance(self):
        return f"Yes I Dance (self.dance) no of times"

class Grandson(son):
    dance = 6
    guitar = 1

    def isdance(self):
        return f"Jackson yeah!" \
               f"Yes I Dance (self.dance) no of times"

darry = Dad()
larry = son()
harry = Grandson()

print(harry.isdance())
print(harry.basketball)