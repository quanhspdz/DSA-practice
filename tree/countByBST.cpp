#include <iostream>
using namespace std;

struct Node {
    string data;
    int counter;
    Node *leftNode;
    Node *rightNode;
};

typedef Node *Tree;

Node *createNode(string data) {
    Node *node = new Node();
    node->data = data;
    node->counter = 1;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

int leftOrRightNode(Node *root, string data) {
    return root->data.compare(data); 
    //< 0 when root->data < data || > 0 when root->data > data || 0 when ==
}

Node *insertNode(Node *root, string data) {
    if (root == NULL) {
        Node *node = createNode(data);
        return node;
    }
    if (leftOrRightNode(root, data) == 0) {
        root->counter++;
    }
    else if (leftOrRightNode(root, data) < 0) {
        root->rightNode = insertNode(root->rightNode, data);
    }
    else if (leftOrRightNode(root, data) > 0) {
        root->leftNode = insertNode(root->leftNode, data);
    }
    return root;
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " " << root->counter << endl;
        preOrder(root->leftNode);
        preOrder(root->rightNode);
    }
}

int countNode(Node *root, string data) {
    if (root == NULL) return 0;
    if (leftOrRightNode(root, data) == 0) {
        return root->counter;
    }
    else if (leftOrRightNode(root, data) > 0) {
        return countNode(root->leftNode, data);
    }
    else return countNode(root->rightNode, data);
}

int main() {
    string data = "quang anh";
    Node *node = createNode(data);
    Node *root = NULL;

    root = insertNode(root, data);
    root = insertNode(root, "zzzzzzzzzz");
    root = insertNode(root, "aaaaaaaaaaa");
    root = insertNode(root, data);
    root = insertNode(root, "afdsfdf");

    cout << countNode(root, "afdsfdf") << endl;

    return 0;
}