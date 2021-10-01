#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct NodeTree
{
    int data;
    struct NodeTree *leftNode;
    struct NodeTree *rightNode;

    NodeTree(int inputData, NodeTree *inputLeft, NodeTree *inputRight)
    {
        data = inputData;
        leftNode = inputLeft;
        rightNode = inputRight;
    }
};

void freeNode(NodeTree *root)
{
    if (root != NULL)
    {
        freeNode(root->rightNode);
        freeNode(root->leftNode);
        delete (root);
    }
}

bool leftOf(int value, NodeTree *root)
{
    return value < root->data;
}
bool rightOf(int value, NodeTree *root)
{
    return value > root->data;
}

NodeTree *insertNode(int value, NodeTree *root)
{
    if (root == NULL)
    {
        NodeTree *node = new NodeTree(value, NULL, NULL);
        return node;
    }
    if (leftOf(value, root))
        root->leftNode = insertNode(value, root->leftNode);
    else if (rightOf(value, root))
        root->rightNode = insertNode(value, root->rightNode);
    return root;
}

void preOrder(NodeTree *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->leftNode);
        preOrder(root->rightNode);
    }
}

void inOrder(NodeTree *root)
{
    if (root != NULL)
    {
        inOrder(root->leftNode);
        cout << root->data << " ";
        inOrder(root->rightNode);
    }
}

void postOrder(NodeTree *root)
{
    if (root != NULL)
    {
        postOrder(root->leftNode);
        postOrder(root->rightNode);
        cout << root->data << " ";
    }
}

bool searchValue(int value, NodeTree *root)
{
    if (root == NULL)
        return false;

    if (value == root->data)
        return true;
    if (leftOf(value, root))
    {
        return searchValue(value, root->leftNode);
    }
    else if (rightOf(value, root))
    {
        return searchValue(value, root->rightNode);
    }

    return false;
}

int LeftMostValue(const NodeTree *root)
{
    while (root->leftNode != NULL)
        root = root->leftNode;
    return root->data;
}

NodeTree *deleteNode(NodeTree *root, int value)
{
    if (root == NULL)
        return root;
    if (leftOf(value, root))
        root->leftNode = deleteNode(root->leftNode, value);
    else if (rightOf(value, root))
        root->rightNode = deleteNode(root->rightNode, value);
    else
    {
        // root->data == value, delete this node
        if (root->leftNode == NULL)
        {
            NodeTree *newRoot = root->rightNode;
            free(root);
            return newRoot;
        }
        if (root->rightNode == NULL)
        {
            NodeTree *newRoot = root->leftNode;
            free(root);
            return newRoot;
        }
        root->data = LeftMostValue(root->rightNode);
        root->rightNode = deleteNode(root->rightNode, root->data);
    }
    return root;
}

int main()
{
    NodeTree *root = NULL;

    int n, x;
    cin >> n >> x;
    int *arr = new int[n];
    int i;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 0; i < n; i++)
    {
        root = insertNode(arr[i], root);
    }

    preOrder(root);
    cout << endl;

    deleteNode(root, x);

    preOrder(root);
    cout << endl;

    freeNode(root);
    return 0;
}