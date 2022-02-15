// WAP using templates to sort a list of elements. Give user the option to perform sorting using Insertion sort, Bubble sort or Selection sort.

#include <iostream>
using namespace std;

template <typename T>
class List
{
    T *arr;
    int capacity;

    void adjust_capacity()
    {
        if (size == capacity)
        {
            T *prev_arr = arr;
            capacity *= 2;
            arr = new T[capacity];
            if (arr == NULL)
            {
                throw "out of memory";
            }
            for (int i = 0; i < size; i++)
            {
                arr[i] = prev_arr[i];
            }
        }
    }

public:
    int size;

    List(int capacity = 1)
    {
        this->capacity = capacity;
        arr = new T[capacity];
        size = 0;
    }

    void insert(T data)
    {
        adjust_capacity();
        arr[size++] = data;
    }

    void ordered_insert(T data)
    {
        adjust_capacity();
        int p = 0;
        while (p < size && arr[p] <= data)
        {
            p++;
        }
        for (int i = size - 1; i >= p; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[p] = data;
        size++;
    }

    void remove(T data)
    {
        int p = 0;
        while (p < size && arr[p] != data)
        {
            p++;
        }
        if (p == size)
        {
            return;
        }
        for (int i = p; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void insertion_sort()
    {
        int j;
        T key;
        for (int i = 1; i < size; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void bubble_sort()
    {
        bool sorted;
        T temp;
        for (int i = 0; i < size - 1; i++)
        {
            sorted = true;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    sorted = false;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            if (sorted)
            {
                break;
            }
        }
    }

    void selection_sort()
    {
        int min_i;
        T temp;
        for (int i = 0; i < size - 1; i++)
        {
            min_i = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[min_i])
                {
                    min_i = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = temp;
        }
    }

    void display()
    {
        if (size == 0)
        {
            cout << "List is empty.\n";
        }
        else
        {
            cout << "Displaying list :\n";
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << ", ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int size;
    cout << "Input size of list : ";
    cin >> size;
    List<int> int_list(size);
    int integer;
    cout << "Input list elements :-\n";
    for (int i = 0; i < size; i++)
    {
        cin >> integer;
        int_list.insert(integer);
    }
    int_list.display();
    int sort_choice;
    cout << "Possible sort types are :-\n1. Insertion\n2. Bubble\n3. Selection\nInput type of sort : ";
    cin >> sort_choice;
    switch (sort_choice)
    {
    case 1:
        int_list.insertion_sort();
        break;
    case 2:
        int_list.bubble_sort();
        break;
    case 3:
        int_list.selection_sort();
        break;
    default:
        cout << "Invalid sort type.\n";
        return 1;
    }
    cout << "List elements sorted. ";
    int_list.display();
    return 0;
}