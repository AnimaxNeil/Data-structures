// WAP to create a Binary Search Tree and include following operations in tree:
// i. Insertion (Recursive and Iterative Implementation)
// ii. Deletion by copying
// iii. Deletion by Merging
// iv. Search a no. in BST
// v. Display its preorder, postorder and inorder traversals Recursively
// vi. Display its preorder, postorder and inorder traversals Iteratively
// vii. Display its level-by-level traversals
// viii. Count the non-leaf nodes and leaf nodes
// ix. Display height of tree
// x. Create a mirror image of tree
// xi. Check whether two BSTs are equal or not

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left_node, *right_node;
    Node(int data)
    {
        this->data = data;
        left_node = right_node = NULL;
    }
};

class BSTree
{
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

    void _delete_nodes(Node *node)
    {
        if (node != NULL)
        {
            _delete_nodes(node->left_node);
            _delete_nodes(node->right_node);
            delete (node);
            node = NULL;
        }
    }

    void _insert_nodes_except(BSTree *bst, Node *node, int del_data)
    {
        if (node != NULL)
        {
            if (node->data != del_data)
            {
                bst->insert_iterative(node->data);
            }
            _insert_nodes_except(bst, node->left_node, del_data);
            _insert_nodes_except(bst, node->right_node, del_data);
        }
    }

    void _insert_nodes_reverse(BSTree *bst, Node *node)
    {
        if (node != NULL)
        {
            bst->_insert_reverse(node->data);
            _insert_nodes_reverse(bst, node->left_node);
            _insert_nodes_reverse(bst, node->right_node);
        }
    }

    void _insert_reverse(int data)
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
            if (node->data < data)
            {
                node = node->left_node;
            }
            else if (node->data > data)
            {
                node = node->right_node;
            }
        }
        if (pre_node->data < data)
        {
            pre_node->left_node = new Node(data);
        }
        else
        {
            pre_node->right_node = new Node(data);
        }
    }

    bool _equals(Node *tree1_node, Node *tree2_node)
    {
        static bool eql = true;
        if (eql == false)
        {
            return eql;
        }
        if (tree1_node != tree2_node)
        {
            eql = false;
            return eql;
        }
        if (tree1_node != NULL && tree2_node != NULL)
        {
            eql = _equals(tree1_node->left_node, tree2_node->left_node);
            if (eql == false)
            {
                return eql;
            }
            eql = _equals(tree1_node->right_node, tree2_node->right_node);
            if (eql == false)
            {
                return eql;
            }
        }
        return eql;
    }

public:
    Node *root_node;

    BSTree()
    {
        root_node = NULL;
    }

    void insert_iterative(int data)
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
                node = node->left_node;
            }
            else if (node->data < data)
            {
                node = node->right_node;
            }
            else
            {
                cout << "Insertion failed. Node already present.\n";
                return;
            }
        }
        if (pre_node->data > data)
        {
            pre_node->left_node = new Node(data);
        }
        else
        {
            pre_node->right_node = new Node(data);
        }
    }
    Node *insert_recursive(int data, Node *node)
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
        return node;
    }

    Node *remove_recursively(int data, Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data > data)
        {
            node->left_node = remove_recursively(data, node->left_node);
        }
        else if (node->data < data)
        {
            node->right_node = remove_recursively(data, node->right_node);
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
            node->left_node = remove_recursively(node->data, node->left_node);
        }
        return node;
    }
    void remove_iteratively(int data)
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
                node = node->left_node;
            }
            else
            {
                node = node->right_node;
            }
        }
        if (node == NULL)
        {
            cout << "Deletion failed. Node not found.\n";
        }
        else if (node->left_node == NULL && node->right_node == NULL)
        {
            if (node == root_node)
            {
                root_node == NULL;
            }
            else if (pre_node->left_node == node)
            {
                pre_node->left_node = NULL;
            }
            else
            {
                pre_node->right_node = NULL;
            }
            delete (node);
        }
        else if (node->left_node == NULL && node->right_node != NULL)
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
        else if (node->left_node != NULL && node->right_node == NULL)
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
        else
        {
            Node *swap_node;
            do
            {
                swap_node = inorderPredecessor(node);
                node->data = swap_node->data;
                pre_node = node;
                node = swap_node;
            } while (node->left_node != NULL);

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
            }
            else
            {
                pre_node->right_node = NULL;
            }
            delete (node);
        }
    }

    void remove_by_copy(int data)
    {
        if (root_node == NULL)
        {
            cout << "Deletion failed. Tree is empty";
            return;
        }
        BSTree *bst = new BSTree();
        _insert_nodes_except(bst, root_node, data);
        _delete_nodes(root_node);
        root_node = bst->root_node;
        delete (bst);
    }

    bool search(int data)
    {
        Node *node = root_node;
        while (node != NULL)
        {
            if (node->data > data)
            {
                node = node->left_node;
            }
            else if (node->data < data)
            {
                node = node->right_node;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    void print_preorder_recursive(const Node *node)
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        if (node != NULL)
        {
            cout << node->data << ", ";
            print_preorder_recursive(node->left_node);
            print_preorder_recursive(node->right_node);
        }
        if (node == root_node)
        {
            cout << "\n";
        }
    }
    void print_postorder_recursive(const Node *node)
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        if (node != NULL)
        {
            print_postorder_recursive(node->left_node);
            print_postorder_recursive(node->right_node);
            cout << node->data << ", ";
        }
        if (node == root_node)
        {
            cout << "\n";
        }
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

    void print_preorder_iteratively()
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        stack<Node *> node_stack;
        Node *node = root_node;
        while (!node_stack.empty() || node != NULL)
        {
            if (node != NULL)
            {
                cout << node->data << ", ";
                if (node->right_node != NULL)
                {
                    node_stack.push(node->right_node);
                }
                node = node->left_node;
            }
            else
            {
                node = node_stack.top();
                node_stack.pop();
            }
        }
        cout << "\n";
    }
    void print_inorder_iteratively()
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        stack<Node *> node_stack;
        Node *node = root_node;
        while (!node_stack.empty() || node != NULL)
        {
            if (node != NULL)
            {
                node_stack.push(node);
                node = node->left_node;
            }
            else
            {
                node = node_stack.top();
                node_stack.pop();
                cout << node->data << ", ";
                node = node->right_node;
            }
        }
        cout << "\n";
    }
    void print_postorder_iteratively()
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        stack<Node *> node_stack;
        Node *node = root_node;
        while (!node_stack.empty() || node != NULL)
        {
            if (node != NULL)
            {
                node_stack.push(node);
                node = node->left_node;
            }
            else
            {
                node = node_stack.top()->right_node;
                if (node == NULL)
                {
                    node = node_stack.top();
                    node_stack.pop();
                    cout << node->data << ", ";
                    while (!node_stack.empty() && node == node_stack.top()->right_node)
                    {
                        node = node_stack.top();
                        node_stack.pop();
                        cout << node->data << ", ";
                    }
                    node = NULL;
                }
            }
        }
        cout << "\n";
    }

    void print_level_by_level()
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        int count = 0, prev_count = 1;
        queue<Node *> node_queue;
        node_queue.push(root_node);
        Node *node;
        while (!node_queue.empty())
        {
            node = node_queue.front();
            if (node->left_node != NULL)
            {
                node_queue.push(node->left_node);
                count++;
            }
            if (node->right_node != NULL)
            {
                node_queue.push(node->right_node);
                count++;
            }
            node_queue.pop();
            prev_count--;
            cout << node->data << ", ";
            if (prev_count == 0)
            {
                cout << "\n";
                prev_count = count;
                count = 0;
            }
        }
    }

    int count_leaf(Node *node)
    {
        static int count = 0;
        if (node->left_node == NULL && node->right_node == NULL)
        {
            return ++count;
        }
        if (node->left_node != NULL)
        {
            count = count_leaf(node->left_node);
        }
        if (node->right_node != NULL)
        {
            count = count_leaf(node->right_node);
        }
        return count;
    }
    int count_non_leaf(Node *node)
    {
        static int count = 0;
        if (node->left_node != NULL)
        {
            count = count_non_leaf(node->left_node);
        }
        if (node->right_node != NULL)
        {
            count = count_non_leaf(node->right_node);
        }
        if (node->left_node != NULL || node->right_node != NULL)
        {
            return ++count;
        }
        return count;
    }

    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return 1 + max(height(node->left_node), height(node->right_node));
    }

    BSTree *get_mirror_image()
    {
        BSTree *bst = new BSTree();
        if (root_node == NULL)
        {
            return bst;
        }
        bst->_insert_nodes_reverse(bst, root_node);
        return bst;
    }

    bool equals(BSTree *bst)
    {
        return _equals(root_node, bst->root_node);
    }
};

int main()
{
    BSTree bst;
    bst.insert_iterative(13);
    bst.insert_iterative(19);
    bst.insert_iterative(17);
    bst.insert_iterative(12);
    bst.root_node = bst.insert_recursive(3, bst.root_node);
    bst.root_node = bst.insert_recursive(9, bst.root_node);
    bst.root_node = bst.insert_recursive(7, bst.root_node);
    bst.root_node = bst.insert_recursive(2, bst.root_node);
    bst.print_inorder_recursive(bst.root_node);
    // bst.print_preorder_recursive(bst.root_node);
    // bst.print_preorder_iteratively();
    // bst.print_postorder_recursive(bst.root_node);
    // bst.print_postorder_iteratively();
    // bst.root_node = bst.remove_recursively(13, bst.root_node);
    bst.remove_iteratively(3);
    bst.print_inorder_iteratively();
    cout << "leaf=" << bst.count_leaf(bst.root_node) << " non-leaf=" << bst.count_non_leaf(bst.root_node) << "\n";
    bst.print_level_by_level();
    cout << "height=" << bst.height(bst.root_node);
    return 0;
}