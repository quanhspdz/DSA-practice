#include<iostream>
using namespace std;

bool isSorted(int arr[], int pos, int n) {
    if (pos == n - 1) return true;
    else {
        if (arr[pos] <= arr[pos + 1]) return isSorted(arr, pos + 1, n);
        else return false;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (isSorted(arr, 0, n)) {
        cout << "true" << endl;
    }
    else cout << "false" << endl;


    return 0;
}