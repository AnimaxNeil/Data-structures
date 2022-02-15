// WAP to calculate factorial and to compute the factors of a given no. (i)using recursion, (ii) using iteration

#include <iostream>
using namespace std;

class Recursion
{
public:
    static int factorial(int num)
    {
        if (num <= 0)
        {
            return 1;
        }
        return num * factorial(num - 1);
    }
    static void print_factors(int num)
    {
        static int i = 1;
        if (i <= num)
        {
            if (num % i == 0)
            {
                cout << i << ", ";
            }
            i++;
            print_factors(num);
        }
    }
};

class Iteration
{
public:
    static int factorial(int num)
    {
        int fact = 1;
        for (int i = 1; i <= num; i++)
        {
            fact *= i;
        }
        return fact;
    }
    static void print_factors(int num)
    {
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                cout << i << ", ";
            }
        }
    }
};

int main()
{
    int num;
    cout << "Input a positive integer : ";
    cin >> num;
    cout << "(i) using recursion\n";
    cout << "Factorial of " << num << " = " << Recursion::factorial(num) << "\n";
    cout << "Factors of " << num << " = ";
    Recursion::print_factors(num);
    cout << "\n";
    cout << "(ii) using iteration\n";
    cout << "Factorial of " << num << " = " << Iteration::factorial(num) << "\n";
    cout << "Factors of " << num << " = ";
    Iteration::print_factors(num);
    cout << "\n";
    return 0;
}