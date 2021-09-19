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
    Node *firstNode = new Node(1, NULL);
    Node *secondNode = new Node(2, NULL);
    Node *thirdNode = new Node (3, NULL);

    firstNode->nextNode = secondNode;
    secondNode->nextNode = thirdNode;

    Node *p = firstNode;
    while (p != NULL) {
        int data = p->data;
        cout << data << " -> ";
        p = p->nextNode;
    }
    cout << "NULL" << endl;


    return 0;
}