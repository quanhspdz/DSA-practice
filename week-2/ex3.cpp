#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int max = arr[0];
    int indexMax = 0;

    for (int i = 0; i < n; i++) {
        if (n - i >= arr[i]) {
            max = arr[i];
            indexMax = i;
        }
    }
    
    if (max > n - indexMax) max = n - indexMax;
    
    cout << max << endl;

    return 0;
}