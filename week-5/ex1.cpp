#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec;
    make_heap(vec.begin(), vec.end());

    int command, v;
    while (n > 0) {
        n--;
        cin >> command;
        switch (command) {
            case 1: {
                cin >> v;
                vec.push_back(v);
                push_heap(vec.begin(), vec.end());
                break;
            }
            case 2: {
                if (!vec.empty()) {
                    cout << vec.front() << endl;
                }
                else {
                    cout << -1 << endl;
                }
                pop_heap(vec.begin(), vec.end());
                vec.pop_back();
                break;
            }
        }
    }
}