#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int *v = new int[n + 2];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v, v + n);

    bool check = false;
    int k = n - 1, coins = 0;
    while (!check && k >= 0) {
        if (s - v[k] < 0) {
            k--;
        } else if (s - v[k] == 0) {
            coins++;
            check = true;
        } else {
            s = s - v[k];
            coins++;
        }
    }

    cout << coins << endl;
    return 0;
}