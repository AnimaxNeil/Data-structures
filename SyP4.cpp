// Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next_node, *prev_node;
    Node(T data)
    {
        this->data = data;
        next_node = prev_node = NULL;
    }
};

template <typename T>
class LinkedListDoubly
{
    Node<T> *head_node;

    void _remove_nodes(Node<T> *node)
    {
        if (node->next_node != NULL)
        {
            _remove_nodes(node->next_node);
        }
        delete (node);
    }

public:
    LinkedListDoubly()
    {
        head_node = NULL;
    }

    bool is_empty()
    {
        return head_node == NULL;
    }

    void insert(T data)
    {
        if (is_empty())
        {
            head_node = new Node<T>(data);
            return;
        }
        Node<T> *node = head_node;
        while (node->next_node != NULL)
        {
            node = node->next_node;
        }
        node->next_node = new Node<T>(data);
        node->next_node->prev_node = node;
    }

    int search(T data)
    {
        int index = 0;
        for (Node<T> *node = head_node; node != NULL; node = node->next_node)
        {
            if (node->data == data)
            {
                return index;
            }
            index++;
        }
        return -1;
    }

    void remove(T data)
    {
        Node<T> *node = head_node;
        if (node->data == data)
        {
            head_node = node->next_node;
            delete (node);
            return;
        }
        while (node->next_node != NULL)
        {
            node = node->next_node;
            if (node->data == data)
            {
                if (node->next_node == NULL)
                {
                    node->prev_node->next_node = NULL;
                    delete (node);
                }
                else
                {
                    node->prev_node->next_node = node->next_node;
                    node->next_node->prev_node = node->prev_node;
                    delete (node);
                }
                return;
            }
        }
        //throw "no such node in list";
        cout << "No such node in list.\n";
    }

    void remove_all_nodes()
    {
        _remove_nodes(head_node);
    }

    void reverse()
    {
        if (is_empty())
        {
            return;
        }
        Node<T> *rev_head_node = new Node<T>(head_node->data);
        for (Node<T> *node = head_node->next_node; node != NULL; node = node->next_node)
        {
            rev_head_node->prev_node = new Node<T>(node->data);
            rev_head_node->prev_node->next_node = rev_head_node;
            rev_head_node = rev_head_node->prev_node;
        }
        remove_all_nodes();
        head_node = rev_head_node;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Displaying linked list :\nNULL <-> ";
        for (Node<T> *node = head_node; node != NULL; node = node->next_node)
        {
            cout << node->data << " <-> ";
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedListDoubly<double> llist1;
    llist1.insert(2.3);
    llist1.insert(-6.21);
    llist1.insert(56);
    llist1.insert(3.14);
    llist1.insert(17.002);
    llist1.insert(12.5);
    llist1.remove(3.14);
    llist1.remove(0.2);
    llist1.display();
    llist1.reverse();
    llist1.display();
    return 0;
}