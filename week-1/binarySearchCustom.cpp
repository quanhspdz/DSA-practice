#include <iostream>
using namespace std;

int binarySearch(long arr[], int l, int h, long x, int &count) {
    if (l <= h) {
        int mid = l + (h - l) / 2;
        if (x == arr[mid]) {
            count++;
            if (mid - 1 >= l) binarySearch(arr, l, mid - 1, x, count);
            if (mid + 1 <= h) binarySearch(arr, mid + 1, h, x, count);
            return mid;
        }
        else if (arr[mid] > x) return  binarySearch(arr, l, mid - 1, x, count);
        else if (arr[mid] < x) return binarySearch(arr, mid + 1, h, x, count);
    }
    return -1;
}

int main() {
    long n, k;
    cin >> n >> k;
    long *arr = new long[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    int result = binarySearch(arr, 0, n - 1, 96, count);
    if (result != -1) {
        cout << count << endl;
    }



    return 0;
}