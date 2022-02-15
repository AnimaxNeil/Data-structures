// Write a program to search an element from a list. Give user the option to perform Linear or Binary search. Use Template functions.

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

    int linear_search(T data)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == data)
            {
                return i;
            }
        }
        return -1;
    }

    int binary_search(T data)
    {
        int low = 0, high = size - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] < data)
            {
                low = mid + 1;
            }
            else if (arr[mid] > data)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
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

void testList()
{
    List<double> *list1 = new List<double>(1);
    list1->ordered_insert(7);
    list1->ordered_insert(9);
    list1->ordered_insert(2);
    list1->ordered_insert(8);
    list1->ordered_insert(7);
    list1->ordered_insert(11);
    list1->display();
    list1->remove(13);
    list1->remove(9);
    list1->display();
}

int old_main()
{
    int size, type_choice, search_choice, search_index;
    List<int> *list1;
    List<double> *dec_list;
    cout << "Input size of list : ";
    cin >> size;
    cout << "Possible list types are :-\n1. integer\n2. decimal\nInput type of list : ";
    cin >> type_choice;
    switch (type_choice)
    {
    case 1:
        list1 = new List<int>(size);
        int integer;
        cout << "Input list elements :-\n";
        for (int i = 0; i < size; i++)
        {
            cin >> integer;
            list1->ordered_insert(integer);
        }
        list1->display();
        break;
    case 2:
        dec_list = new List<double>(size);
        double decimal;
        cout << "Input list elements :-\n";
        for (int i = 0; i < size; i++)
        {
            cin >> decimal;
            dec_list->ordered_insert(decimal);
        }
        dec_list->display();
        break;
    default:
        cout << "Invalid list type.";
        return 1;
    }
    cout << "Possible search types are :-\n1. linear\n2. binary\nInput type of search : ";
    cin >> search_choice;
    switch (search_choice)
    {
    case 1:
        switch (type_choice)
        {
        case 1:
            int integer;
            cout << "Input search element : ";
            cin >> integer;
            search_index = list1->linear_search(integer);
            break;
        case 2:
            double decimal;
            cout << "Input search element : ";
            cin >> decimal;
            search_index = dec_list->linear_search(decimal);
            break;
        }
        break;
    case 2:
        switch (type_choice)
        {
        case 1:
            int integer;
            cout << "Input search element : ";
            cin >> integer;
            search_index = list1->binary_search(integer);
            break;
        case 2:
            double decimal;
            cout << "Input search element : ";
            cin >> decimal;
            search_index = dec_list->binary_search(decimal);
            break;
        }
        break;
    default:
        cout << "Invalid search type.";
        return 1;
    }
    if (search_index == -1)
    {
        cout << "Element not present in list.\n";
    }
    else
    {
        cout << "Element found at position : " << search_index + 1 << "\n";
    }
    return 0;
}

int main()
{
    int size;
    cout << "Input size of list : ";
    cin >> size;
    List<int> list1(size);
    int input_element;
    cout << "Input list elements :-\n";
    for (int i = 0; i < size; i++)
    {
        cin >> input_element;
        list1.ordered_insert(input_element);
    }
    list1.display();
    int search_choice, search_index, search_element;
    cout << "Input search element : ";
    cin >> search_element;
    cout << "Possible search types are :-\n1. linear\n2. binary\nInput type of search : ";
    cin >> search_choice;
    switch (search_choice)
    {
    case 1:
        search_index = list1.linear_search(search_element);
        break;
    case 2:
        search_index = list1.binary_search(search_element);
        break;
    default:
        cout << "Invalid search type.";
        return 1;
    }
    if (search_index == -1)
    {
        cout << "Element not present in list.\n";
    }
    else
    {
        cout << "Element found at position : " << search_index + 1 << "\n";
    }
    return 0;
}