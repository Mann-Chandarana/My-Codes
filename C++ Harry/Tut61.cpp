// Write theory from video(Tut 61)
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // connecting our file with hout stream
    //ofstream hout("Sample60.txt"); // hout object of class ofstream

    // Creating a name string and filling it with the string entered by user
    // string name;
    // cout << "Enter your name";
    // cin >> name;

    // // Writing a string to the file
    // hout << "My name is" + name;
    // hout.close();// To close file

    ifstream hin("Sample60b.txt"); //hin object of class ifstream
    string content;
    getline(hin, content); // This lines means content of file is stored in variable content through hin
    cout << "The content of this file is: " << content;
    hin.close();
    return 0;
}