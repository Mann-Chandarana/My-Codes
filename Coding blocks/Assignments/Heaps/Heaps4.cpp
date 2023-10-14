#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(){};
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class PersonCompare
{
public:
    bool operator()(Person A, Person B)
    {
        return A.age < B.age;
    }
};

int main()
{
    priority_queue<Person, vector<Person>, PersonCompare> pq;

    int n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        Person P(name, age);
        pq.push(P);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        Person q = pq.top();
        cout << "Name is " << q.name << " and his/her age is " << q.age << endl;
        pq.pop();
    }

    return 0;
}