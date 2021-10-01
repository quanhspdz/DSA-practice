#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *nextNode;
    
    Node(int iData, Node *iNextNode) {
        data = iData;
        nextNode = iNextNode;
    }
};
typedef struct Node *Queue;

Node *creatNode(int data) {
    Node *node = new Node(data, NULL);
    return node;
}

bool queueIsEmpty(Queue queue) {
    return (queue == NULL);
}

void enQueue(Queue &queue, int data) {
    Node *newQueue = new Node(data, NULL);
    if (queueIsEmpty(queue)) {
        queue = newQueue;
    }
    else {
        Queue tmpQueue = queue;
        while (tmpQueue != NULL && tmpQueue->nextNode != NULL) {
            tmpQueue = tmpQueue->nextNode;
        }
        tmpQueue->nextNode = newQueue;
    }
}

int peakQueue(Queue queue) {
    if (queueIsEmpty(queue)) {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    else {
        return queue->data;
    }
}

int deQueue(Queue &queue) {
    if (queueIsEmpty(queue)) {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    else {
        int data = queue->data;
        Queue oldQueue = queue;
        queue = queue->nextNode;
        delete(oldQueue);
        return data;
    }
}


int main() {
    Queue queue = NULL;
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);

    cout << "Top: " << peakQueue(queue) << endl;
    while (queue != NULL) {
        cout << "Top " << deQueue(queue) << endl;
    }

    return 0;
}