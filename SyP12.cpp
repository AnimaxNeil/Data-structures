// WAP to display Fibonacci series (i)using recursion, (ii) using iteration

#include <iostream>
using namespace std;

class Recursion
{
public:
    static void print_fibonacci(int count)
    {
        static int t1 = 0, t2 = 1, t3, count0 = count;
        if (count > 0)
        {
            if (count0 - count == 0)
            {
                cout << t1 << ", ";
            }
            else if (count0 - count == 1)
            {
                cout << t2 << ", ";
            }
            else
            {
                t3 = t1 + t2;
                t1 = t2;
                t2 = t3;
                cout << t3 << ", ";
            }
            print_fibonacci(count - 1);
        }
    }
};

class Iteration
{
public:
    static void print_fibonacci(int count)
    {
        int t1 = 0, t2 = 1, t3;
        for (int i = 1; i <= count; i++)
        {
            if (i == 1)
            {
                cout << t1 << ", ";
            }
            else if (i == 2)
            {
                cout << t2 << ", ";
            }
            else
            {
                t3 = t1 + t2;
                t1 = t2;
                t2 = t3;
                cout << t3 << ", ";
            }
        }
    }
};

int main()
{
    int num;
    cout << "Input numbers of terms : ";
    cin >> num;
    cout << "(i) using recursion\n";
    cout << "Fibonacci series -> ";
    Recursion::print_fibonacci(num);
    cout << "\n";
    cout << "(ii) using iteration\n";
    cout << "Fibonacci series -> ";
    Iteration::print_fibonacci(num);
    cout << "\n";
    return 0;
}