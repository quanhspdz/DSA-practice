#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> vec;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        cout << vec.at(i) << " ";
    }

    cout << endl;

    return 0;
}