// WAP to convert the Sparse Matrix into non-zero form and vice-versa.

#include <iostream>
using namespace std;

class MatrixConversion
{
public:
    static void print0form(int **arr, int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "{ ";
            for (int j = 0; j < columns; j++)
            {
                cout << arr[i][j];
                if (j < columns - 1)
                {
                    cout << ", ";
                }
            }
            cout << " }\n";
        }
    }

    static void printNon0form(int **arr, int count)
    {
        for (int i = 0; i < count; i++)
        {
            cout << "{ " << arr[i][0] << ", " << arr[i][1] << ", " << arr[i][2] << " }\n";
        }
    }

    static int numOfNon0elements(int **arr, int rows, int columns)
    {
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }

    static int **toNon0form(int **z0form, int rows, int columns)
    {
        int count = numOfNon0elements(z0form, rows, columns);
        int **non0form = new int *[count];
        for (int i = 0; i < count; i++)
        {
            non0form[i] = new int[3];
        }
        int k = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (z0form[i][j] != 0)
                {
                    non0form[k][0] = i;
                    non0form[k][1] = j;
                    non0form[k][2] = z0form[i][j];
                    k++;
                }
            }
        }
        return non0form;
    }

    static int **to0form(int **non0form, int count, int rows, int columns)
    {
        int **z0form = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            z0form[i] = new int[columns]{0};
        }
        for (int i = 0; i < count; i++)
        {
            z0form[non0form[i][0]][non0form[i][1]] = non0form[i][2];
        }
        return z0form;
    }
};

int main()
{
    const int rows = 6, columns = 3;
    int matrix[rows][columns] = {{0, 2, 0}, {0, 4, 6}, {0, 0, 3}, {5, 0, 1}, {0, 0, 0}, {0, 0, 9}};
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = matrix[i][j];
        }
    }
    cout << "Given Zero form :-\n";
    MatrixConversion::print0form(arr, rows, columns);
    cout << "Zero form to Non-zero form :-\n";
    int **arr1 = MatrixConversion::toNon0form(arr, rows, columns);
    int count = MatrixConversion::numOfNon0elements(arr, rows, columns);
    MatrixConversion::printNon0form(arr1, count);
    cout << "Non-zero form to Zero form :-\n";
    int **arr0 = MatrixConversion::to0form(arr1, count, rows, columns);
    MatrixConversion::print0form(arr0, rows, columns);
    return 0;
}