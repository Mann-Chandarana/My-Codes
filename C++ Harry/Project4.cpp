#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

///////////////////////////////////////////////////////////
// Created by Mann Chandarana
// Roll no - 20CS011
void Get_Time(int H, int M, int S)
{
    char str[10];
    fstream infile;
    infile.open("Time.txt", ios::out | ios::binary);
    sprintf(str, "%02d:%02d:%02d", H, M, S);
    infile.write((char *)str, sizeof(str));
    infile.close();
}
///////////////////////////////////////////////////////////
void display_time(int H, int M, int S)
{
    char str[10];
    fstream outfile;
    outfile.open("Time.txt", ios::in);
    sscanf(str, "%02d,%02d,%02d", &H, &M, &S);
    outfile.read((char *)str, sizeof(str));
    cout << "The time is " << setw(2) << setfill('0') << H << ":" << setw(2) << setfill('0') << M << ":" << setw(2) << setfill('0') << S << endl;
}
////////////////////////////////////////////////////////////
int main()
{
    int HH, MIN, SS;
    cout << "****************************************************************" << endl;
    cout << "Enter time in form of Hours,Minutes,Seconds " << endl;
    cin >> HH >> MIN >> SS;
    Get_Time(HH, MIN, SS);
    cout << "Your time is added to your file : " << endl;
    cout << endl;
    cout << "Reading data from the file : " << endl;
    display_time(HH, MIN, SS);
    cout << "****************************************************************" << endl;

    return 0;
}