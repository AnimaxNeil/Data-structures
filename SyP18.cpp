// WAP to implement Diagonal Matrix using one-dimensional array.

#include <iostream>
using namespace std;

class DiagonalMatrix
{
    int *arr;
    int length;

public:
    int rank;

    DiagonalMatrix(int rank)
    {
        this->rank = rank;
        length = rank;
        arr = new int[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = 0;
        }
    }

    void set_elements(int elements[], int size)
    {
        if (size > length)
        {
            cout << "Invalid number of elements";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = elements[i];
        }
    }

    void set_element(int diagonal_index, int element)
    {
        if (diagonal_index < 0 || diagonal_index >= length)
        {
            cout << "Invalid position";
            return;
        }
        arr[diagonal_index] = element;
    }

    int get_element(int row_index, int column_index)
    {
        if (row_index < 0 || column_index < 0 || row_index >= rank || column_index >= rank)
        {
            cout << "Invalid position";
            throw "Invalid position";
        }
        if (row_index != column_index)
        {
            return 0;
        }
        return arr[row_index];
    }

    void print()
    {
        for (int i = 0; i < rank; i++)
        {
            cout << "| ";
            for (int j = 0; j < rank; j++)
            {
                cout << get_element(i, j) << " ";
            }
            cout << "|\n";
        }
    }
};

int main()
{
    DiagonalMatrix dm(4);
    int elements[] = {11, 3, -7, 24};
    dm.set_elements(elements, 4);
    dm.print();
    return 0;
}
