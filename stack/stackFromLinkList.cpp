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
typedef struct Node *Stack;

bool stackIsEmpty(Stack stack) {
    return (stack == NULL);
}
Node *creatNode(int data) {
    Node *node = new Node(data, NULL);
    return node;
}
void pushStack(Stack &stack, int data) {
    Node *pointer = new Node(data, NULL);

    if (stackIsEmpty(stack)) {
        stack = pointer;
    }
    else {
        pointer->nextNode = stack;
        stack = pointer;
    }
}
int peakStack(Stack stack) {
    if (stackIsEmpty(stack)) {
        cout << "Stack is empty!" << endl;
        return -1;
    } 
    else {
        return stack->data;
    }
}
int popStack(Stack &stack) {
    if (stackIsEmpty(stack)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    else {
        int data = stack->data;

        Stack newStack = stack;
        stack = stack->nextNode;
        delete(newStack);

        return data;
    }
}

int main() {
    Stack stack;
    pushStack(stack, 1);
    pushStack(stack, 2);
    pushStack(stack, 3);
    pushStack(stack, 4);

    cout << "Top: " << peakStack(stack) << endl;
    cout << "Top: " << popStack(stack) << endl;

    while (!stackIsEmpty(stack)) {
        int data = stack->data;
        popStack(stack);
        cout << "Top: " << data << endl;
    }

    delete(stack);
    return 0;
}