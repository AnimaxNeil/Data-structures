#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;
    Node(int data)
    {
        this->data = data;
        this->next_node = NULL;
    }
};

class LinkedList
{
private:
    Node *head_node;
    void _remove_nodes(Node *node);

public:
    LinkedList();
    ~LinkedList();
    void insert_first(int data);
    void insert_last(int data);
    void insert_at(int index, int data);
    void insert_last(const LinkedList *llist);
    void remove_first();
    void remove_last();
    void remove_all_nodes();
    void remove_at(int index);
    void remove(int data);
    bool is_empty();
    int search(int data);
    int count();
    void reverse();
    LinkedList *concat(const LinkedList *llist);
    LinkedList *operator+(const LinkedList llist);
    void display();
};

LinkedList::LinkedList()
{
    head_node = NULL;
}

LinkedList::~LinkedList()
{
    remove_all_nodes();
}

void LinkedList::insert_first(int data)
{
    Node *node = new Node(data);
    node->next_node = head_node;
    head_node = node;
}

void LinkedList::insert_last(int data)
{
    if (is_empty())
    {
        insert_first(data);
        return;
    }
    Node *node = head_node;
    while (node->next_node != NULL)
    {
        node = node->next_node;
    }
    node->next_node = new Node(data);
}

bool LinkedList::is_empty()
{
    return head_node == NULL;
}

int LinkedList::count()
{
    int cnt = 0;
    for (Node *node = head_node; node != NULL; node = node->next_node)
    {
        cnt++;
    }
    return cnt;
}

void LinkedList::insert_at(int index, int data)
{
    if (index == 0)
    {
        insert_first(data);
    }
    else if (index > 0 && index <= count())
    {
        Node *node = head_node;
        for (int i = 1; i < index; i++)
        {
            node = node->next_node;
        }
        Node *old = node->next_node;
        node->next_node = new Node(data);
        node->next_node->next_node = old;
    }
    else
    {
        //throw "no node at given index";
        cout << "No node at given index.\n";
    }
}

void LinkedList::remove_first()
{
    if (is_empty())
    {
        //throw "list is empty";
        cout << "List is empty.\n";
        return;
    }
    Node *old = head_node;
    head_node = head_node->next_node;
    delete (old);
}

void LinkedList::remove_last()
{
    if (is_empty())
    {
        //throw "list is empty";
        cout << "List is empty.\n";
        return;
    }
    Node *node = head_node;
    while (node->next_node->next_node != NULL)
    {
        node = node->next_node;
    }
    delete (node->next_node);
    node->next_node = NULL;
}

void LinkedList::_remove_nodes(Node *node)
{
    if (node->next_node != NULL)
    {
        _remove_nodes(node->next_node);
    }
    delete (node);
    node = NULL;
}

void LinkedList::remove_all_nodes()
{
    _remove_nodes(head_node);
}

void LinkedList::remove_at(int index)
{
    if (is_empty())
    {
        //throw "list is empty";
        cout << "List is empty.\n";
        return;
    }
    if (index == 0)
    {
        remove_first();
    }
    else if (index == count() - 1)
    {
        remove_last();
    }
    else if (index > 0 && index < count() - 1)
    {
        Node *node = head_node;
        for (int i = 1; i < index; i++)
        {
            node = node->next_node;
        }
        Node *old = node->next_node;
        node->next_node = node->next_node->next_node;
        delete (old);
    }
    else
    {
        //throw "no node at given index";
        cout << "No node at given index.\n";
    }
}

int LinkedList::search(int data)
{
    int index = 0;
    for (Node *node = head_node; node != NULL; node = node->next_node)
    {
        if (node->data == data)
        {
            return index;
        }
        index++;
    }
    return -1;
}

void LinkedList::remove(int data)
{
    Node *node = head_node, *pre_node;
    if (node->data == data)
    {
        head_node = head_node->next_node;
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

void LinkedList::reverse()
{
    if (is_empty())
    {
        return;
    }
    Node *rev_head_node = new Node(head_node->data);
    Node *rev_node;
    for (Node *node = head_node->next_node; node != NULL; node = node->next_node)
    {
        rev_node = new Node(node->data);
        rev_node->next_node = rev_head_node;
        rev_head_node = rev_node;
    }
    remove_all_nodes();
    head_node = rev_head_node;
}

void LinkedList::insert_last(const LinkedList *llist)
{
    Node *node = head_node;
    while (node->next_node != NULL)
    {
        node = node->next_node;
    }
    node->next_node = llist->head_node;
}

LinkedList *LinkedList::concat(const LinkedList *llist)
{
    LinkedList *cllist = new LinkedList();
    if (is_empty())
    {
        return cllist;
    }
    for (Node *node = head_node; node != NULL; node = node->next_node)
    {
        cllist->insert_last(node->data);
    }
    for (Node *node = llist->head_node; node != NULL; node = node->next_node)
    {
        cllist->insert_last(node->data);
    }
    return cllist;
}

LinkedList *LinkedList::operator+(const LinkedList llist)
{
    return concat(&llist);
}

void LinkedList::display()
{
    if (is_empty())
    {
        cout << "List is empty.\n";
        return;
    }
    cout << "Displaying linked list :\n";
    for (Node *node = head_node; node != NULL; node = node->next_node)
    {
        cout << node->data << " -> ";
    }
    cout << "NULL\n";
}

void testlist()
{
    cout << "Linked List program...\n";
    LinkedList *llist1 = new LinkedList();
    llist1->insert_last(29);
    llist1->insert_first(3);
    llist1->insert_first(7);
    llist1->insert_last(19);
    llist1->insert_last(17);
    llist1->display();
    llist1->insert_at(0, 1);
    llist1->insert_at(2, 22);
    llist1->display();
    cout << "no. of nodes = " << llist1->count() << endl;
    llist1->insert_at(llist1->count(), 32);
    llist1->insert_at(llist1->count() + 1, 32);
    llist1->display();
    llist1->remove_first();
    llist1->insert_last(31);
    llist1->remove_last();
    llist1->display();
    llist1->remove_at(2);
    llist1->remove_at(0);
    llist1->display();
    cout << "no. of nodes = " << llist1->count() << endl;
    llist1->remove_at(llist1->count() - 1);
    llist1->remove_at(llist1->count());
    llist1->display();
    llist1->insert_last(42);
    llist1->insert_last(44);
    llist1->display();
    llist1->remove(42);
    llist1->display();
    llist1->reverse();
    llist1->display();
    LinkedList *llist2 = new LinkedList();
    llist2->insert_last(-9);
    llist2->insert_first(-13);
    llist2->insert_last(-7);
    llist2->display();
    //llist1 = llist1->concat(llist2);
    llist1 = (*llist1) + (*llist2);
    llist1->display();
}

int main()
{
    testlist();
    return 0;
}