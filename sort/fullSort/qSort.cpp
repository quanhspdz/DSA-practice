#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int l, int h) {
    int p = arr[h];
    int currentPos = l;
    for (int i = l; i < h; i++) {
        if (arr[i] < p) {
            swap(&arr[i], &arr[currentPos++]);
        }
    }
    swap(&arr[currentPos], &arr[h]);
    return currentPos;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int m = partition(arr, l, h);
        quickSort(arr, l, m - 1);
        quickSort(arr, m + 1, h);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    
    return 0;
}