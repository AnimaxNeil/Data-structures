// Perform Queues operations using Circular Array implementation. Use Templates.

#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    int capacity, front, rear;
    T *arr;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new T[capacity];
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (((rear + 1) % capacity == front) || (rear == capacity - 1 && front == -1));
    }

    void enqueue(const T &data)
    {
        if (isFull())
        {
            throw "Queue overflow";
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw "Queue underflow";
        }
        front = (front + 1) % capacity;
        return arr[front];
    }

    T peek(int position)
    {
        if (!(position - 1 >= 0 && position <= count()))
        {
            throw "invalid position";
        }
        return arr[(front + position) % capacity];
    }

    int count()
    {
        return rear > front ? rear - front : rear + (capacity - front);
    }

    void display()
    {
        cout << "Displaying queue elements: ";
        for (int i = front + 1; i != rear + 1; i = (i + 1) % capacity)
        {
            cout << arr[i] << ",";
        }
        cout << "\n";
    }
};

int main()
{
    Queue<int> queue1(8);
    queue1.enqueue(3);
    queue1.enqueue(2);
    queue1.enqueue(6);
    queue1.enqueue(7);
    queue1.enqueue(9);
    queue1.display();
    queue1.dequeue();
    queue1.dequeue();
    queue1.display();
    cout << "Element at position 2 : " << queue1.peek(2) << "\n";
    return 0;
}