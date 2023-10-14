#include <iostream>
using namespace std;
//////////////////////////////////////////////
class stack
{
public:
    int top, size;
    int *arr;
};
///////////////////////////////////////////////
void push(stack *&sp, int value)
{
    if (sp->top == sp->size - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        sp->top++;
        //cout<<sp->top;
        sp->arr[sp->top] = value;
    }
}
////////////////////////////////////////////////
void pop(stack *&sp)
{
    if (sp->top == -1)
    {
        cout << "Stack underflow " << endl;
    }
    else
    {
        sp->top--;
    }
}
////////////////////////////////////////////////
void show_top(stack *sp)
{
    cout << sp->arr[sp->top] << endl;
}
int peek(stack *sp, int i)
{
    int index = sp->top - i + 1;
    if (index < 0)
    {
        cout << "Invalid position" << endl;
        return -1;
    }
    else
    {
        return sp->arr[index];
    }
}
int main()
{
    stack *sp;
    sp->top = -1;
    sp->size = 10;
    sp->arr = new int[sp->size];

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);

    for (int i = 1; i <= sp->top +1; i++)
    {
        cout<<peek(sp, i)<<endl;
    }

    // show_top(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // show_top(sp);

    return 0;
}