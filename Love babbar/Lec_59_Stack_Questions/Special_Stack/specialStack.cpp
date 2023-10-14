#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    // Define the data members.
    stack<int> s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    void push(int data)
    {
        // For first element
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        s.pop();

        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMini;
        }
    }

    int top()
    {
        if (s.empty())
            return -1;
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};

int main()
{
    SpecialStack st;
    st.push(5);
    st.push(3);
    st.push(8);
    st.push(2);
    st.push(4);

    cout << "Min: " << st.getMin() << endl;
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Min: " << st.getMin() << endl;
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Min: " << st.getMin() << endl;
    cout << "Top: " << st.top() << endl;

    st.push(-1);
    st.push(10);
    st.push(13);
    cout << "Min: " << st.getMin() << endl;
    cout << "Top: " << st.top() << endl;

    return 0;
}