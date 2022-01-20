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

// Level order Build
Node *buildTree()
{

    queue<Node *> level;

    int temp;
    cin >> temp;
    Node *root = new Node(temp);
    level.push(root);

    while (!level.empty())
    {
        Node *n1 = NULL, *n2 = NULL;
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            n1 = new Node(c1);
            level.push(n1);
        }
        if (c2 != -1)
        {
            n2 = new Node(c2);
            level.push(n2);
        }
        // Attack the two read nodes to front and pop it.
        level.front()->left = n1;
        level.front()->right = n2;
        level.pop();
    }
    return root;
}

// Print in pre order
void printInPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printInPreOrder(root->left);
    printInPreOrder(root->right);
}

// Print in in order
void printInInOrder(Node *root)
{
    if (root == NULL)
        return;
    printInInOrder(root->left);
    cout << root->data << " ";
    printInInOrder(root->right);
}

// Print in post order
void printInPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printInPostOrder(root->left);
    printInPostOrder(root->right);
    cout << root->data << " ";
}

// Print in level ordder
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

// Print in level
void printInLevel(Node *root, int level)
{
    queue<Node *> levels;
    levels.push(root);
    levels.push(NULL);
    int k = 1;
    while (!levels.empty() && levels.front() != NULL)
    {
        Node *temp = levels.front();
        cout << levels.front()->data << " ";

        if (temp->left != NULL)
        {
            levels.push(temp->left);
        }
        if (temp->right != NULL)
        {
            levels.push(temp->right);
        }

        levels.pop();
        if (levels.front() == NULL)
        {
            cout << endl;
            levels.pop();
            levels.push(NULL);
            k++;
        }
    }
}

// Height of tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

// Minimum height of tree
int minHeightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int h1 = minHeightOfTree(root->left);
    int h2 = minHeightOfTree(root->right);

    if (h1 == 0)
        return 1 + h2;
    if (h2 == 0)
        return 1 + h1;

    return 1 + min(minHeightOfTree(root->left), minHeightOfTree(root->right));
}

// Diameter O(n^2)
int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max({D1, D2, D3});
}

// Diameter  O(n)
pair<int, int> diameterEfficient(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> hd = {0, 0};
        return hd;
    }

    pair<int, int> hd;
    // Calculating left and right height
    int h1 = diameterEfficient(root->left).first;
    int h2 = diameterEfficient(root->right).first;
    // Left and right diameter
    int d1 = diameterEfficient(root->left).second;
    int d2 = diameterEfficient(root->right).second;

    hd.first = 1 + max(h1, h2);
    hd.second = max({h1 + h2, d1, d2});

    return hd;
}

vector<int> path;
void printPaths(Node *root)
{
    // Base Case

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        path.push_back(root->data);
        int len = path.size();
        for (int i = 0; i < len; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        path.pop_back();
        return;
    }

    // Processing
    path.push_back(root->data);
    printPaths(root->left);
    printPaths(root->right);
    path.pop_back();
}

// Morris Traversal Inorder
void morrisTraversalInorder(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr, curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

// Morris Traversal Preorder
void morrisTraversalPreorder(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                cout << curr->data << " ";
                prev->right = curr, curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    // 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
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
    printInLevel(root, 3);
    cout << endl;
    cout << "Height of the tree is" << endl;
    cout << height(root) << endl;
    cout << "Min Height of the tree is" << endl;
    cout << minHeightOfTree(root) << endl;
    cout << "Diameter of the tree is" << endl;
    cout << diameter(root) << endl;
    cout << "Diameter of the tree efficient is" << endl;
    cout << diameterEfficient(root).second << endl;
    cout << "All the paths from root to leaf nodes" << endl;
    printPaths(root);
    cout << "Morris Traversal Inorder" << endl;
    morrisTraversalInorder(root);
    cout << "Morris Traversal Preorder" << endl;
    morrisTraversalPreorder(root);
}