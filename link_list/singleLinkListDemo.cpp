#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *nextNode;

    Node(int inputData, Node *inputNextNode) {
        data = inputData;
        nextNode = inputNextNode;
    }
};


int main () {

    Node *startNode = new Node(1, NULL);
    Node *preNode = startNode;
    for (int i = 1; i < 10; i++) {
        Node *newNode = new Node(i + 1, NULL);
        preNode->nextNode = newNode;
        preNode = newNode;
    }
    
    Node *node = startNode;
    while (node != NULL) {
        cout << node->data << endl;
        node = node->nextNode;
    }

    return 0;
}