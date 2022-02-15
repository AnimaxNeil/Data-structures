// Implement Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list and concatenate two linked lists (include a function and also overload operator +).

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next_node;
    Node(T data)
    {
        this->data = data;
        next_node = NULL;
    }
};

template <typename T>
class LinkedList
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
    LinkedList()
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
        Node<T> *node = head_node, *pre_node;
        if (node->data == data)
        {
            head_node = node->next_node;
            delete (node);
            return;
        }
        while (node->next_node != NULL)
        {
            pre_node = node;
            node = node->next_node;
            if (node->data == data)
            {
                if (node->next_node == NULL)
                {
                    pre_node->next_node = NULL;
                    delete (node);
                }
                else
                {
                    pre_node->next_node = node->next_node;
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
        Node<T> *rev_node;
        for (Node<T> *node = head_node->next_node; node != NULL; node = node->next_node)
        {
            rev_node = new Node<T>(node->data);
            rev_node->next_node = rev_head_node;
            rev_head_node = rev_node;
        }
        remove_all_nodes();
        head_node = rev_head_node;
    }

    LinkedList concat(const LinkedList &llist)
    {
        LinkedList<T> cllist;
        if (is_empty())
        {
            return cllist;
        }
        for (Node<T> *node = head_node; node != NULL; node = node->next_node)
        {
            cllist.insert(node->data);
        }
        for (Node<T> *node = llist.head_node; node != NULL; node = node->next_node)
        {
            cllist.insert(node->data);
        }
        return cllist;
    }

    LinkedList operator+(const LinkedList &llist)
    {
        return concat(llist);
    }

    void display()
    {
        if (is_empty())
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Displaying linked list :\n";
        for (Node<T> *node = head_node; node != NULL; node = node->next_node)
        {
            cout << node->data << " -> ";
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedList<float> llist1;
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
    LinkedList<float> llist2;
    llist2.insert(-0.5);
    llist2.insert(22.7);
    llist2.insert(3);
    llist2.display();
    //llist1 = llist1.concat(llist2);
    llist1 = llist1 + llist2;
    llist1.display();
    return 0;
}