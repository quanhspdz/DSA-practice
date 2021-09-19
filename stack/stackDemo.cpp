#include <iostream>
using namespace std;

const int maxStackSize = 1000;
int currentStackSize = -1;
int stack[maxStackSize];

bool stackIsEmpty() {
    return (currentStackSize == -1);
}
bool stackIsFull() {
    return (currentStackSize == maxStackSize);
}
void pushStack(int data) {
    if (!stackIsFull()) {
        currentStackSize++;
        stack[currentStackSize] = data;
    }
    else {
        cout << "Stack is full!" << endl;
    }
}
int peakStack() {
    if (!stackIsEmpty()) {
        return stack[currentStackSize];
    }
    else {
        cout << "Stack is empty!" << endl;
        return -1;
    }
}
int popStack() {
    if (!stackIsEmpty()) {
        int data = stack[currentStackSize];
        currentStackSize--;
        return data;
    }
    else {
        cout << "Stack is empty!" << endl;
        return -1;
    }
}

int main () {
    pushStack(1);
    pushStack(2);
    pushStack(3);
    pushStack(4);

    cout << "Top of stack: " << peakStack() << endl;
    while (!stackIsEmpty()) {
        int data = popStack();
        cout << data << " <- ";
    }
    cout << "NULL" << endl;
    
    if (stackIsEmpty()) {
        cout << "This is the end, mother sucker!" << endl;
    }

    return 0;
}