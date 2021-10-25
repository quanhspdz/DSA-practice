#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr = {};
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        cout << arr.at(i) << " ";
        if (i == n - 1) {
            cout << endl;
        }
    }
    
    if (binary_search(arr.begin(), arr.end(), x)) {
        cout << "found x" << endl;
        vector<int>::iterator low, up;
        low = lower_bound(arr.begin(), arr.end(), x);
        up = upper_bound(arr.begin(), arr.end(), x);
        cout << "lower_bound at position " << low - arr.begin() << endl;
        cout << "upper_bound at position " << up - arr.begin() - 1 << endl;
    } else {
        cout << "not found x" << endl;
    }
   

    return 0;
}