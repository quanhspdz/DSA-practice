#include <iostream>
#include <algorithm>
using namespace std;

int num_of_tower(int arr[], int k, int n) {
    sort(arr, arr + n);
    int numTowers = 0;
    int i = 0;
    while (i < n) {
        numTowers++;
        int loc = arr[i] + k;
        while (i < n && arr[i] <= loc)
            i++;
        i--;
        loc = arr[i] + k;
        while (i < n && arr[i] <= loc) 
            i++;
    }

    return numTowers;
}

int main() {
    int n, k;
    cin >> n >> k;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   cout << num_of_tower(arr, k, n) << endl;

    return 0;
}