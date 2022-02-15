// Perform Stack operations using Linked List implementation.

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next_node;
    Node(T data)
    {
        this->data = data;
        next_node = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *top;

    void _display(const Node<T> *node)
    {
        if (node->next_node != NULL)
        {
            _display(node->next_node);
        }
        cout << node->data << ",";
    }

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(const T &data)
    {
        Node<T> *node = new Node<T>(data);
        if (node == NULL)
        {
            throw "out of memory";
        }
        node->next_node = top;
        top = node;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw "stack underflow";
        }
        Node<T> *node = top;
        top = top->next_node;
        T *data = new T(node->data);
        delete (node);
        return *data;
    }

    T peek(int position)
    {
        Node<T> *node = top;
        for (int i = 1; i < position && node != NULL; i++)
        {
            node = node->next_node;
        }
        if (node == NULL)
        {
            throw "imvalid position";
        }
        return *(new T(node->data));
    }

    int count()
    {
        int c = 0;
        for (Node<T> *node = top; node != NULL; node = node->next_node)
        {
            c++;
        }
        return c;
    }

    void display()
    {
        cout << "Displaying stack elements: ";
        _display(top);
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