#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    int command, x;
    queue<int> queueNum;
    
    while (n > 0) {
        cin >> command;
        switch(command) {
            case 1: {
                cin >> x;
                queueNum.push(x);
                break;
            }
            case 2: {
                queueNum.pop();
                break;
            }
            case 3: {
                cout << queueNum.front() << endl;
            }
        }

        n--;
    }


    return 0;
}