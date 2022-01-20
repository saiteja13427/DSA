#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Searching A BST
// O(H) Complexity
// O(logn) (Proper Structure) <= O(H) <= O(N)(Skewed Tree)
bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;
    if (key > root->data)
        return search(root->right, key);

    return search(root->left, key);
}

// Building BST recursive
Node *insertRecursive(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);

    if (data > root->data)
        root->right = insertRecursive(root->right, data);
    else
        root->left = insertRecursive(root->left, data);

    return root;
}

// Building BST iterative
Node *insert(Node *root, int data)
{
    Node *temp = new Node(data);
    if (root == NULL)
    {
        return temp;
    }
    else
    {
        Node *itr = root;
        while (true)
        {
            if (data > itr->data && itr->right != NULL)
            {
                itr = itr->right;
            }
            else if (data > itr->data && itr->right == NULL)
            {
                itr->right = temp;
                break;
            }
            else if (data < itr->data && itr->left != NULL)
            {
                itr = itr->left;
            }
            else if (data < itr->data && itr->left == NULL)
            {
                itr->left = temp;
                break;
            }
        }
    }
    return root;
}

// Finding the minimum value in a given tree
Node *findMin(Node *root)
{
    if (root->left == NULL)
        return root;
    return findMin(root->left);
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else if (key < root->data)
        root->left = deleteNode(root->left, key);
    else
    {
        // No children node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // One children node
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }

        // Two children node
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (auto &x : arr)
        root = insert(root, x);
    printInOrder(root);
    cout << endl;
    cout << search(root, 12) << endl;
    deleteNode(root, 1);
    printInOrder(root);
}