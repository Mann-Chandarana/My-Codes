#include <iostream>
using namespace std;
///////////////////////////////////////
template <class T>
class stack
{
public:
    int top, size;
    T *arr;
};
///////////////////////////////////////
void push(stack<string> *sp, string w)
{
    if (sp->top == sp->size - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=w;
    }
}
///////////////////////////////////////
void pop(stack<string> *sp)
{
    if (sp->top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        sp->top--;
    }
}
///////////////////////////////////////
string top(stack<string> *sp)
{
    return sp->arr[sp->top];
}
///////////////////////////////////////
bool isEmpty(stack<string> *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}
///////////////////////////////////////
void reverse(string s)
{
    stack<string> *sp;
    sp->top = -1;
    sp->size = 20;
    sp->arr = new string[sp->size];
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        push(sp, word);
    }
    while (!isEmpty(sp))
    {
        cout << sp->arr[sp->top] << " ";
        pop(sp);
    }
}
///////////////////////////////////////

int main()
{
    string s;
    getline(cin, s);
    reverse(s);
    return 0;
}