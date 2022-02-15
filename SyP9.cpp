// Create and perform different operations on Double-ended Queues using Linked List implementation.

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
class DEQueue
{
    Node<T> *front, *rear;

public:
    DEQueue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue_front(T data)
    {
        Node<T> *node = new Node<T>(data);
        node->next_node = front;
        if (isEmpty())
        {
            rear = node;
        }
        front = node;
    }

    void enqueue_rear(T data)
    {
        if (isEmpty())
        {
            front = rear = new Node<T>(data);
            return;
        }
        rear->next_node = new Node<T>(data);
        rear = rear->next_node;
    }

    T dequeue_front()
    {
        if (isEmpty())
        {
            throw "Queue underflow";
        }
        Node<T> *node = front;
        front = front->next_node;
        T *data = new T(node->data);
        delete (node);
        if (isEmpty())
        {
            rear = NULL;
        }
        return *data;
    }

    T dequeue_rear()
    {
        if (isEmpty())
        {
            throw "Queue underflow";
        }
        Node<T> *node = front;
        if (node == rear)
        {
            front = rear = NULL;
            T *data = new T(node->data);
            delete (node);
            return *data;
        }
        while (node->next_node != rear)
        {
            node = node->next_node;
        }
        T *data = new T(node->next_node->data);
        delete (node->next_node);
        node->next_node = NULL;
        return *data;
    }

    int count()
    {
        int c = 0;
        for (Node<T> *node = front; node != NULL; node = node->next_node)
        {
            c++;
        }
        return c;
    }

    void display()
    {
        cout << "Displaying DEQueue elements : \n";
        for (Node<T> *node = front; node != NULL; node = node->next_node)
        {
            cout << node->data << ", ";
        }
        cout << "\n";
    }
};

int main()
{
    DEQueue<int> dq;
    dq.enqueue_front(4);
    dq.enqueue_front(2);
    dq.enqueue_rear(6);
    dq.enqueue_rear(9);
    dq.enqueue_front(1);
    dq.enqueue_rear(1);
    dq.display();
    dq.dequeue_front();
    dq.dequeue_rear();
    dq.display();
}