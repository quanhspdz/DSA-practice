#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    int position = low, partitonVale = arr[high];

    for (int j = low; j < high; j++) {
        if (arr[j] < partitonVale) {
            swap(&arr[j], &arr[position++]);
        }
    }
    swap(&arr[position], &arr[high]);
    return (position);
}

void quickSortIncrease(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortIncrease(arr, low, p - 1);
        quickSortIncrease(arr, p + 1, high);
    }
}

int binarySearch(int arr[], int l, int h, int x, int &count) {
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

int countCouple(int arr[], int n, long k) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        binarySearch(arr, i + 1, n -1, arr[i] + k, count);
        binarySearch(arr, i + 1, n -1, arr[i] - k, count);
    }

    return count;
}

int main() {   
    int n, k;
    cin >> n >> k;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSortIncrease(arr, 0, n - 1);

    cout << countCouple(arr, n, k) << endl;

    return 0;
}