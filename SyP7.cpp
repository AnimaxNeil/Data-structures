// Perform Stack operations using Array implementation. Use Templates.

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    int capacity, limit, top;
    T *arr;

    void adjust_capacity()
    {
        if (top + 1 == capacity)
        {
            T *prev_arr = arr;
            capacity *= 2;
            arr = new T[capacity];
            if (arr == NULL)
            {
                throw "out of memory";
            }
            for (int i = 0; i <= top; i++)
            {
                arr[i] = prev_arr[i];
            }
        }
    }

public:
    Stack(int capacity = 1, int limit = 0)
    {
        this->capacity = capacity;
        this->limit = limit;
        arr = new T[capacity];
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(const T &data)
    {
        if (limit > 0 && top + 1 == limit)
        {
            throw "Stack overflow";
        }
        adjust_capacity();
        arr[++top] = data;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw "Stack underflow";
        }
        return arr[top--];
    }

    T peek(int position)
    {
        if (!(position >= 1 && position <= count()))
        {
            throw "invalid position";
        }
        return arr[position - 1];
    }

    int count()
    {
        return top + 1;
    }

    void display()
    {
        cout << "Displaying stack elements: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << ",";
        }
        cout << "\n";
    }
};

int main()
{
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(2);
    stack1.push(6);
    stack1.push(7);
    stack1.push(9);
    stack1.display();
    stack1.pop();
    stack1.pop();
    stack1.display();
    cout << "Element at position 2 : " << stack1.peek(2) << "\n";
    return 0;
}