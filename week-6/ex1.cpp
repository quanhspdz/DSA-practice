#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int command, id;
    string name;
    map<int, string> m;
    while (n > 0) {
        n--;
        cin >> command;
        switch (command) {
            case 1: {
                cin >> id >> name;
                m[id] = name;
                break;
            }
            case 2: {
                cin >> id;
                m.erase(id);
                break;
            }
            case 3: {
                cin >> id;
                if (m.find(id) == m.end()) {
                    cout << "n/a" << endl;
                } else {
                    cout << m[id] << endl;
                }
            }
        }
    }

    return 0;
}