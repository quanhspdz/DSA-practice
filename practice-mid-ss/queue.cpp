#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> numQueue;
    int n;
    cin >> n;

    int command, x;
    while (n > 0) {
        n--;
        cin >> command;
        switch (command) {
            case 1: {
                cin >> x;
                numQueue.push(x);
                break;
            }
            case 2: {
                cout << numQueue.front() << endl;
                break;
            }
            case 3: {
                cout << numQueue.back() << endl;
                break;
            }
            case 4: {
                cout << numQueue.front() << endl;
                numQueue.pop();
                cout << numQueue.front() << endl;
                break;
            }
        }
    }

    return 0;
}