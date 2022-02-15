// WAP to calculate GCD of 2 number (i) with recursion (ii) without recursion

#include <iostream>
using namespace std;

class Recursion
{
public:
    static int gcd(int num1, int num2)
    {
        if (num1 > num2)
        {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        if (num2 % num1 == 0)
        {
            return num1;
        }
        return gcd(num2 % num1, num1);
    }
};

class Iteration
{
public:
    static int gcd(int num1, int num2)
    {
        int temp;
        if (num1 > num2)
        {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        while (num2 % num1 != 0)
        {
            temp = num2 % num1;
            num2 = num1;
            num1 = temp;
        }
        return num1;
    }
};

int main()
{
    int num1, num2;
    cout << "Input 2 numbers.\n";
    cin >> num1 >> num2;
    cout << "(i) using recursion\n";
    cout << "GCD of " << num1 << " and " << num2 << " = " << Recursion::gcd(num1, num2);
    cout << "\n";
    cout << "(ii) using iteration\n";
    cout << "GCD of " << num1 << " and " << num2 << " = " << Iteration::gcd(num1, num2);
    cout << "\n";
}