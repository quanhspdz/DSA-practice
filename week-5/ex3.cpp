#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

template<typename T> 
class custom_priority_queue : public priority_queue<T, vector<T>, greater<T>> {
    public:
        bool remove(T& value) {
            auto it = find(this->c.begin(), this->c.end(), value);
            if (it != this->c.end()) {
                this->c.erase(it);
                make_heap(this->c.begin(), this->c.end(), this->comp);
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    custom_priority_queue<int> pqueue;
    int n;
    cin >> n;

    int command, v;
    while (n > 0) {
        n--;
        cin >> command;
        switch (command) {
            case 1: {
                //insert to heap
                cin >> v;
                pqueue.push(v);
                break;
            }
            case 2: {
                //delete v 
                cin >> v;
                pqueue.remove(v);
                break;
            }
            case 3: {
                //show max
                if (!pqueue.empty()) {
                    cout << pqueue.top() << endl;
                }
                else {
                    cout << -1 << endl;
                }
                break;
            }
        }
    }
 
    return 0;
}