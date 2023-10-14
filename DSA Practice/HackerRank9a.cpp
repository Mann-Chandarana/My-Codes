#include <iostream>
using namespace std;
////////////////////////////
class stack
{
public:
    int top;
    int *arr;
    int size;
};
////////////////////////////
int isFull(stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}
////////////////////////////
void push(stack *&sp, int value)
{
    if (isFull(sp))
    {
        cout << "Stack overflow" << endl;
        return;
    }

    sp->top++;
    sp->arr[sp->top] = value;
}
////////////////////////////
void pop(stack *&sp)
{
    if (sp->top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    sp->top--;
}
////////////////////////////
int top(stack *sp)
{
    return sp->arr[sp->top];
}
////////////////////////////
int main()
{
    stack *sp = new (stack);
    sp->size = 100;
    sp->top = -1;
    sp->arr = new int[sp->size];

    int n, x, query, mx;
    cin >> n;
    while (n--)
    {
        cin >> query;
        if (query == 1)
        {
            cin >> x;
            push(sp, x);
            //cout << top(sp)<<endl;
        }
        else if (query == 2)
        {
            pop(sp);
            //cout << top(sp);
        }
        else if (query == 3)
        {
            mx = sp->arr[0];
            for (int i = 1; i <= sp->top; i++)
            {
                if (mx < sp->arr[i])
                {
                    mx = sp->arr[i];
                }
            }
            cout << mx << endl;
        }
    }

    return 0;
}