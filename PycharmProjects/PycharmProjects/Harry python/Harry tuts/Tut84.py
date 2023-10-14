import pickle
# To store python object and lock it
# Pickling a python object
# cars = ["Audi","BMW","Maruti suzuki"]
# file = "mycar.pkl"
# fileobj = open(file,'wb') # write binary
# pickle.dump(cars,fileobj)
# fileobj.close()


# To read binary file
file = "mycar.pkl"
fileobj = open(file,'rb')  # read binary
mycar = pickle.load(fileobj)
print(mycar)
print(type(mycar))