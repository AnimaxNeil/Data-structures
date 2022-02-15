// WAP to implement Symmectric Matrix using one-dimensional array.

#include <iostream>
using namespace std;

class SymmetricMatrix
{
    int *arr;
    int length;

public:
    int rank;

    SymmetricMatrix(int rank)
    {
        this->rank = rank;
        length = rank * (rank + 1) / 2;
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

    void set_element(int column_wise_triangular_index, int element)
    {
        if (column_wise_triangular_index < 0 || column_wise_triangular_index >= length)
        {
            cout << "Invalid position";
            return;
        }
        arr[column_wise_triangular_index] = element;
    }

    int get_element(int row_index, int column_index)
    {
        if (row_index < 0 || column_index < 0 || row_index >= rank || column_index >= rank)
        {
            cout << "Invalid position";
            throw "Invalid position";
        }
        if (row_index < column_index)
        {
            int temp = row_index;
            row_index = column_index;
            column_index = temp;
        }
        return arr[(row_index * (row_index + 1) / 2) + column_index];
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
    SymmetricMatrix sm(4);
    int elements[] = {3, 1, 3, -7, 24, 8, 9, 1, -18, 1};
    sm.set_elements(elements, 10);
    sm.print();
    return 0;
}
