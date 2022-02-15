// WAP to implement various operations on AVL Tree.

#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left_node, *right_node;
    Node(int data)
    {
        this->data = data;
        height = 1;
        left_node = right_node = NULL;
    }
};

class AVLTree
{
    Node *root_node;

    int getHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    void updateHeight(Node *node)
    {
        node->height = 1 + max(getHeight(node->left_node), getHeight(node->right_node));
    }

    int getBalanceFactor(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return getHeight(node->left_node) - getHeight(node->right_node);
    }

    Node *leftRotate(Node *node)
    {
        Node *r_node = node->right_node;
        Node *r_l_node = r_node->left_node;
        r_node->left_node = node;
        node->right_node = r_l_node;
        updateHeight(node);
        updateHeight(r_node);
        return r_node;
    }

    Node *rightRotate(Node *node)
    {
        Node *l_node = node->left_node;
        Node *l_r_node = l_node->right_node;
        l_node->right_node = node;
        node->left_node = l_r_node;
        updateHeight(node);
        updateHeight(l_node);
        return l_node;
    }

    Node *inorderPredecessor(Node *node)
    {
        if (node == NULL)
        {
            cout << "Node is null";
            return NULL;
        }
        if (node->left_node == NULL)
        {
            Node *predecessor = NULL, *temp_node = root_node;
            while (temp_node != NULL || temp_node != node)
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
        while (node->right_node != NULL)
        {
            node = node->right_node;
        }
        return node;
    }

    Node* insert_recursive(int data, Node *node)
    {
        if (node == NULL)
        {
            return new Node(data);
        }
        if (node->data > data)
        {
            node->left_node = insert_recursive(data, node->left_node);
        }
        else if (node->data < data)
        {
            node->right_node = insert_recursive(data, node->right_node);
        }
        else
        {
            return node;
        }
        updateHeight(node);
        int bf = getBalanceFactor(node);

        if (bf > 1 && data < node->left_node->data) //left-left
        {
            return rightRotate(node);
        }
        if (bf < -1 && data > node->right_node->data) //right-right
        {
            return leftRotate(node);
        }
        if (bf > 1 && data > node->left_node->data) //left-right
        {
            node->left_node = leftRotate(node->left_node);
            return rightRotate(node);
        }
        if (bf < -1 && data < node->right_node->data) //right-left
        {
            node->right_node = rightRotate(node->right_node);
            return leftRotate(node);
        }
        return node;
    }

    Node *remove_recursive(int data, Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data > data)
        {
            node->left_node = remove_recursive(data, node->left_node);
        }
        else if (node->data < data)
        {
            node->right_node = remove_recursive(data, node->right_node);
        }
        else
        {
            if (node->left_node == NULL && node->right_node == NULL)
            {
                delete (node);
                return NULL;
            }
            if (node->left_node == NULL && node->right_node != NULL)
            {
                Node *next_node = node->right_node;
                delete (node);
                return next_node;
            }
            if (node->left_node != NULL && node->right_node == NULL)
            {
                Node *next_node = node->left_node;
                delete (node);
                return next_node;
            }
            node->data = inorderPredecessor(node)->data;
            node->left_node = remove_recursive(node->data, node->left_node);
        }

        if (node == NULL)
        {
            return node;
        }
        updateHeight(node);
        int bf = getBalanceFactor(node);

        if (bf > 1 && getBalanceFactor(node->left_node) >= 0) //left-left
        {
            return rightRotate(node);
        }
        if (bf < -1 && getBalanceFactor(node->right_node) <= 0) //right-right
        {
            return leftRotate(node);
        }
        if (bf > 1 && getBalanceFactor(node->left_node) < 0) //left-right
        {
            node->left_node = leftRotate(node->left_node);
            return rightRotate(node);
        }
        if (bf < -1 && getBalanceFactor(node->right_node) > 0) //right-left
        {
            node->right_node = rightRotate(node->right_node);
            return leftRotate(node);
        }
        return node;
    }

    void print_inorder_recursive(const Node *node)
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        if (node != NULL)
        {
            print_inorder_recursive(node->left_node);
            cout << node->data << ", ";
            print_inorder_recursive(node->right_node);
        }
        if (node == root_node)
        {
            cout << "\n";
        }
    }

public:
    AVLTree()
    {
        root_node = NULL;
    }

    void insert(int data)
    {
        root_node = insert_recursive(data, root_node);
    }

    void remove(int data)
    {
        root_node = remove_recursive(data, root_node);
    }
    
    void print()
    {
        print_inorder_recursive(root_node);
    }
};

int main()
{
    AVLTree avl;
    avl.insert(7);
    avl.insert(2);
    avl.insert(13);
    avl.insert(5);
    avl.insert(19);
    avl.insert(23);
    avl.insert(12);
    avl.insert(72);
    avl.insert(6);
    avl.insert(52);
    avl.remove(12);
    avl.print();
    return 0;
}