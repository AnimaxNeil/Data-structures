// WAP to implement Upper Triangular Matrix using one-dimensional array.

#include <iostream>
using namespace std;

class UpperTriangularMatrix
{
    int *arr;
    int length;

public:
    int rank;

    UpperTriangularMatrix(int rank)
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
            arr[size - 1 -i] = elements[i];
        }
    }

    void set_element(int column_wise_triangular_index, int element)
    {
        if (column_wise_triangular_index < 0 || column_wise_triangular_index >= length)
        {
            cout << "Invalid position";
            return;
        }
        arr[length - 1 - column_wise_triangular_index] = element;
    }

    int get_element(int row_index, int column_index)
    {
        if (row_index < 0 || column_index < 0 || row_index >= rank || column_index >= rank)
        {
            cout << "Invalid position";
            throw "Invalid position";
        }
        if (row_index > column_index)
        {
            return 0;
        }
        row_index = rank - 1 - row_index;
        column_index = rank - 1 - column_index;
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
    UpperTriangularMatrix utm(4);
    int elements[] = {-9, 6, 3, -7, 24, 8, 9, 1, -18, 69};
    utm.set_elements(elements, 10);
    utm.print();
    return 0;
}
