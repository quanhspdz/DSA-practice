#include <iostream>
#include <stack>
using namespace std;

int main() {

    int n;
    cin >> n;
    stack<int> stackNum;
    int command, x;

    while (n > 0) {
        cin >> command;
        switch(command) {
            case 1: {
                cin >> x;
                stackNum.push(x);
                break;
            }
            case 2: {
                stackNum.pop();
                break;
            }
            case 3: {
                cout << stackNum.top() << endl;
            } 
        }

        n--;
    }


    return 0;
}