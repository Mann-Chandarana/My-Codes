// To draw flowchart from video of Tut59 // pepcoding
#include <iostream>
#include <fstream> //Use for input and output of files
using namespace std;
/*
The useful classes for working with files in  c++
1. fstreambase
2. ifstream --> derived from fstreambase
3. ofstream --> derived from fstreambase
*/

/*
In order to work with files in c++, you will have to open it. Primarily, there are 2 ways to open it.
1) Using constructor
2) Using the member function open() of the class
*/
int main()
{
    string st = "Mann is a good boy";
    // Opening files using constructor and writing it
    ofstream out("Sample60.txt"); // Write operation, Here out is a object of class ofstream 
    out << st;

    string st2;
    // Opening files using constructor and reading it
    ifstream in("Sample60b.txt"); // Read operation, Here in is a object of class ifstream
    //in >> st2;
    getline(in, st2);
    cout << st2;
    return 0;
}
