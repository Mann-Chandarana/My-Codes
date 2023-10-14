// Write theroy from video of Tut69 and Tut70
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    cout << "Displaying this vector " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        //cout << v.at(i) << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> vec1; // Zero length vector
    int element, size = 5;
    // cout << "Enter the size of the vector" << endl;
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter an element to add this vector: ";
    //     cin >> element;
    //     vec1.push_back(element); // It add elements in line
    // }
    //vec1.pop_back(); // It removes last element
    // display(vec1);
    // vector<int>::iterator iter = vec1.begin();
    //vec1.insert(iter + 1, 5, 566);
    // display(vec1);

    vector<char> vec2(4); // 4-element character vector
    vec2.push_back('5');
    //display(vec2);
    vector<char> vec3(vec2); // 4-element character vector from vec2
    //display(vec3);
    vector<int> vec4(4, 13); // 6-element vector of 3s
    //display(vec4);
    cout << vec4.size();

    return 0;
}