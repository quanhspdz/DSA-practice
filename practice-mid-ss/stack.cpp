#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> numStack;
    int n;
    cin >> n;

    int command, x;
    while (n > 0) {
        n--;
        cin >> command;
        switch (command) {
            case 1: {
                cin >> x;
                numStack.push(x);
                break;
            }
            case 2: {
                if (!numStack.empty()) {
                    cout << numStack.top() << endl;
                } else {
                    cout << "stack is empty!" << endl;
                }
                break;
            }
            case 3: {
                if (!numStack.empty()) {
                    cout << numStack.top() << endl;
                    numStack.pop();
                } else {
                    cout << "stack is empty!" << endl;
                }
                break;
            }
        }
    }

    return 0;
}