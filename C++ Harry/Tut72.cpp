#include <iostream>
#include <list>
using namespace std;
void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    list<int> list1; // list of 0 length
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);

    // Sorting the list
    //list1.sort();
    // display(list1);

    // Reversing the list
    list1.reverse();
    display(list1);
    //display(list1);
    // Removing element from list
    //list1.pop_back(); // it removes element from back
    // list1.pop_front(); // it removes element from front
    // list1.remove(9);   // Removing element from list
    // display(list1);
    // list<int>::iterator iter;
    // iter = list1.begin();
    // cout << *iter << " ";
    // iter++;

    list<int> list2(3); //Empty list of size 3
    list<int>::iterator iter;
    iter = list2.begin();
    *iter = 4;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;
    display(list2);
    list1.sort();
    list2.sort();
    list1.merge(list2);
    cout << "After Merging: ";
    display(list1);

    return 0;
}