// WAP to reverse the order of the elements in the stack using additional queue.

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
void reverse(stack<T> &stk)
{
    queue<T> rev_que;
    while (!stk.empty())
    {
        rev_que.push(stk.top());
        stk.pop();
    }
    while (!rev_que.empty())
    {
        stk.push(rev_que.front());
        rev_que.pop();
    }
}
template <typename T>
void _print(stack<T> stk)
{
    if (stk.empty())
    {
        return;
    }
    T elm = stk.top();
    stk.pop();
    cout << elm << ", ";
    _print(stk);
    stk.push(elm);
}
template <typename T>
void print(const stack<T> &stk)
{
    int i = 0;
    cout << "[ ";
    _print(stk);
    cout << "]\n";
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(3);
    stk.push(9);
    cout << "Given stack : ";
    print(stk);
    reverse(stk);
    cout << "Reversed stack : ";
    print(stk);
    return 0;
}