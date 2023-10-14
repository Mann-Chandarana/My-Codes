#include <iostream>
using namespace std;
// Brief overview of Polymorphism in OOPS CPP.

//Example of functiopn overloading.
class funcOverload
{
public:
	void fun() { cout << "I am a fucntion with no argument\n"; }

	void fun(int x) { cout << "I am a fucntion with int argument\n"; }

	void fun(double x) { cout << "I am a fucntion with double argument\n"; }
};

//Operator overloading
class complex
{
private:
	int real, img;

public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(int r, int i)
	{
		real = r;
		img = i;
	}

	complex operator+(complex &c)
	{
		complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;

		return temp;
	}

	void getValue()
	{
		cout << "Real = " << real << " and Imag = " << img << endl;
	}
};

//Function overwriting
class base
{
public:
	virtual void print() { cout << "This is the base class's print function\n"; }
	void display() { cout << "This is the base class's display function\n"; }
};

class derived : public base
{
public:
	void print() { cout << "This is the derived class's print function\n"; }
	void display() { cout << "This is the derived class's display function\n"; }
};

int main()
{
	int n;
	cin >> n;

	// funcOverload obj;
	// obj.fun();
	// obj.fun(4);
	// obj.fun(5.6);

	// complex c1(5,6),c2(6,5);
	// complex c3 = c1 + c2;
	// c3.getValue();

	base *baseptr;
	derived d;
	baseptr = &d;

	baseptr -> print();
	baseptr -> display();

	return 0;
}