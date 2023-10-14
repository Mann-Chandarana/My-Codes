class Employee:
    def __init__(self,fname,lname):
        self.fname = fname
        self.lname = lname
        self.email = f"{fname}.{lname}@code with harry.com"

    def explain(self):
        return f"This employee is {self.fname} {self.lname}"

    def printemail(self):
        pass

Mann_Chandarana = Employee("Mann","Chandarana")
Parth_Rathod = Employee("Parth","Rathod")

# print(Mann_Chandarana.explain())
# print(Mann_Chandarana.email)

#### For Changing name
class Employee:
    def __init__(self,fname,lname):
        self.fname = fname
        self.lname = lname
        #self.email = f"{fname}.{lname}@code with harry.com"

    def explain(self):
        return f"This employee is {self.fname} {self.lname}"

    @property ##### If We want to use function as property
    def email(self):
        if self.fname ==None or self.lname==None:
            return "Email is not set. Please set it using setter"
        return f"{self.fname}.{self.lname}@code with harry.com"

    @email.setter ####Setter
    def email(self,string):
        print("Setting now ...")
        names = string.split("@")[0]
        self.fname = names.split(".")[0]
        self.lname = names.split(".")[1]

    @email.deleter
    def email(self):
        self.fname = None
        self.lname = None



Mann_Chandarana = Employee("Mann","Chandarana")
Parth_Rathod = Employee("Parth","Rathod")

# print(Mann_Chandarana.explain())
# print(Mann_Chandarana.email)

Mann_Chandarana.email = "this.that@code with harry.com"
print(Mann_Chandarana.email)

Mann_Chandarana.fname = "Harshil"
print(Mann_Chandarana.email)
del Mann_Chandarana.email
print(Mann_Chandarana.email)