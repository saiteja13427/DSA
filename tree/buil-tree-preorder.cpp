#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

// Preorder Build
Node *buildTree()
{

    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printInPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printInPreOrder(root->left);
    printInPreOrder(root->right);
}

void printInInOrder(Node *root)
{
    if (root == NULL)
        return;
    printInInOrder(root->left);
    cout << root->data << " ";
    printInInOrder(root->right);
}

void printInPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printInPostOrder(root->left);
    printInPostOrder(root->right);
    cout << root->data << " ";
}

void printInLevelOrder(Node *root)
{
    queue<Node *> level;
    level.push(root);
    while (!level.empty())
    {
        cout << level.front()->data << " ";
        if (level.front()->left != NULL)
            level.push(level.front()->left);
        if (level.front()->right != NULL)
            level.push(level.front()->right);
        if (!level.empty())
            level.pop();
    }
}

void printInLevel(Node *root)
{
    queue<Node *> level;
    level.push(root);
    level.push(NULL);
    while (level.front() != NULL)
    {
        cout << level.front()->data << " ";
        if (level.front()->left != NULL)
            level.push(level.front()->left);
        if (level.front()->right != NULL)
            level.push(level.front()->right);
        if (!level.empty())
            level.pop();
        if (level.front() == NULL)
        {
            cout << endl;
            level.pop();
            level.push(NULL);
        }
    }
}

int main()
{
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();
    cout << "Preorder" << endl;
    printInPreOrder(root);
    cout << endl;
    cout << "Inorder" << endl;
    printInInOrder(root);
    cout << endl;
    cout << "Postorder" << endl;
    printInPostOrder(root);
    cout << endl;
    cout << "Levelorder" << endl;
    printInLevelOrder(root);
    cout << endl;
    cout << "In Level" << endl;
    printInLevel(root);
}