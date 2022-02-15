// WAP to create a Threaded Binary Tree as per inorder traversal, and implement operations like finding the successor / predecessor of an element, insert an element, inorder traversal.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    bool left_isParent, right_isParent;
    Node *left_node, *right_node;
    Node(int data)
    {
        this->data = data;
        left_isParent = right_isParent = true;
        left_node = right_node = NULL;
    }
};

class ThreadedBST
{
    Node *root_node;

public:
    ThreadedBST()
    {
        root_node = NULL;
    }

    Node *inorderPredecessor(Node *node)
    {
        if (node == NULL)
        {
            cout << "Node is null";
            return NULL;
        }
        if (node->left_node == NULL || node->left_isParent)
        {
            Node *predecessor = NULL, *temp_node = root_node;
            while (temp_node != node)
            {
                if (node->data < temp_node->data)
                {
                    temp_node = temp_node->left_node;
                }
                else
                {
                    predecessor = temp_node;
                    temp_node = temp_node->right_node;
                }
            }
            return predecessor;
        }
        node = node->left_node;
        while (node->right_node != NULL && !node->right_isParent)
        {
            node = node->right_node;
        }
        return node;
    }

    Node *inorderSuccessor(Node *node)
    {
        if (node == NULL)
        {
            cout << "Node is null";
            return NULL;
        }
        if (node->right_node == NULL || node->right_isParent)
        {
            Node *successor = NULL, *temp_node = root_node;
            while (temp_node != node)
            {
                if (node->data < temp_node->data)
                {
                    successor = temp_node;
                    temp_node = temp_node->left_node;
                }
                else
                {
                    temp_node = temp_node->right_node;
                }
            }
            return successor;
        }
        node = node->right_node;
        while (node->left_node != NULL && !node->left_isParent)
        {
            node = node->left_node;
        }
        return node;
    }

    void insert(int data)
    {
        if (root_node == NULL)
        {
            root_node = new Node(data);
            return;
        }
        Node *node = root_node, *pre_node;
        while (node != NULL)
        {
            pre_node = node;
            if (node->data > data)
            {
                node = node->left_isParent ? NULL : node->left_node;
            }
            else if (node->data < data)
            {
                node = node->right_isParent ? NULL : node->right_node;
            }
            else
            {
                cout << "Insertion failed. Node already present.\n";
                return;
            }
        }
        // cout<<"preNode="<<pre_node->data;
        if (pre_node->data > data)
        {
            pre_node->left_node = new Node(data);
            pre_node->left_isParent = false;
            pre_node->left_node->left_node = inorderPredecessor(pre_node->left_node);
            pre_node->left_node->right_node = inorderSuccessor(pre_node->left_node);
        }
        else
        {
            pre_node->right_node = new Node(data);
            // cout<<"new_node="<<pre_node->right_node->data;
            // cout<<"Predecessor="<<inorderPredecessor(pre_node->right_node)->data;
            pre_node->right_isParent = false;
            pre_node->right_node->left_node = inorderPredecessor(pre_node->right_node);
            pre_node->right_node->right_node = inorderSuccessor(pre_node->right_node);
        }
    }

    void remove(int data)
    {
        if (root_node == NULL)
        {
            cout << "Deletion failed. Node is empty.\n";
            return;
        }
        Node *node = root_node, *pre_node;
        while (node != NULL && node->data != data)
        {
            pre_node = node;
            if (node->data > data)
            {
                node = node->left_isParent ? NULL : node->left_node;
            }
            else
            {
                node = node->right_isParent ? NULL : node->right_node;
            }
        }
        if (node == NULL)
        {
            cout << "Deletion failed. Node not found.\n";
        }
        else if ((node->left_node == NULL || node->left_isParent) && (node->right_node == NULL || node->right_isParent))
        {
            if (node == root_node)
            {
                root_node == NULL;
            }
            else if (pre_node->left_node == node)
            {
                pre_node->left_node = inorderPredecessor(pre_node);
                pre_node->left_isParent = true;
            }
            else
            {
                pre_node->right_node = inorderSuccessor(pre_node->right_node);
                pre_node->right_isParent = true;
            }
            delete (node);
        }
        else if ((node->left_node == NULL || node->left_isParent) && (node->right_node != NULL && !node->right_isParent))
        {
            if (node == root_node)
            {
                root_node == node->right_node;
            }
            else if (pre_node->left_node == node)
            {
                pre_node->left_node = node->right_node;
            }
            else
            {
                pre_node->right_node = node->right_node;
            }
            delete (node);
        }
        else if ((node->left_node != NULL && !node->left_isParent) && (node->right_node == NULL || node->right_isParent))
        {
            if (node == root_node)
            {
                root_node == node->left_node;
            }
            else if (pre_node->left_node == node)
            {
                pre_node->left_node = node->left_node;
            }
            else
            {
                pre_node->right_node = node->left_node;
            }
            delete (node);
        }
        else if ((node->left_node != NULL && !node->left_isParent) && (node->right_node != NULL && !node->right_isParent))
        {
            Node *swap_node;
            do
            {
                swap_node = inorderPredecessor(node);
                node->data = swap_node->data;
                pre_node = node;
                node = swap_node;
            } while (node->left_node != NULL && !node->left_isParent);
            node = pre_node->left_node;
            while (node != swap_node)
            {
                pre_node = node;
                if (node->data > swap_node->data)
                {
                    node = node->left_node;
                }
                else
                {
                    node = node->right_node;
                }
            }
            if (pre_node->left_node == node)
            {
                pre_node->left_node = NULL;
                pre_node->left_node = inorderPredecessor(pre_node);
                pre_node->left_isParent = true;
            }
            else
            {
                pre_node->right_node = node->right_node;
                pre_node->right_isParent = true;
            }
            delete (node);
        }
        else
        {
            cout << "Deletion failed. Unexpected error.";
        }
    }

    void print_inorder()
    {
        Node *node = root_node;
        while (node->left_node != NULL)
        {
            node = node->left_node;
        }
        while (node != NULL)
        {
            cout << node->data << ", ";
            if (node->right_node != NULL && !node->right_isParent)
            {
                node = node->right_node;
                while (node->left_node != NULL && !node->left_isParent)
                {
                    node = node->left_node;
                }
            }
            else
            {
                node = node->right_node;
            }
        }
        cout << "\n";
    }
};

int main()
{
    ThreadedBST tbst;
    tbst.insert(13);
    tbst.insert(11);
    tbst.insert(12);
    tbst.insert(2);
    tbst.insert(3);
    tbst.insert(31);
    tbst.insert(23);
    tbst.remove(11);
    tbst.print_inorder();
    return 0;
}