#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> vec {2, 3, 5, 2, 5, 6, 2, 7, 3, 1, 0};
    make_heap(vec.begin(), vec.end());
    cout << vec.front() << endl;
    
    vec.push_back(69);
    push_heap(vec.begin(), vec.end());
    cout << vec.front() << endl;

    pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    cout << vec.front() << endl;

    

    return 0;
}