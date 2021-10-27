#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        m[arr[i]] = i;
    }

    bool check = false;
    for (int i = 0; i < n; i++) {
        if (m.find(k - arr[i]) != m.end()) {
            if (i < m[k - arr[i]]) {
                cout << ++i << " " << ++m[k - arr[i]] << endl;
                check = true;
            }
        }
    }

    if (!check) {
        cout << -1 << endl;
    }

    return 0;
}