#include <iostream>
using namespace std;

int *merge(int arr1[], int n1, int arr2[], int n2) {
    int *arr = new int[n1 + n2];
    for (int i = 0; i < n1; i++) 
        arr[i] = arr1[i];
    for (int i = 0; i < n2; i++) {
        arr[i + n1] = arr2[i];
    }
    return arr;
}

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

int binarySearch(int arr[], int l, int h, int x) {
    if (l <= h) {
        int mid = l + (h - l) / 2;
        if (x == arr[mid]) {
            return mid;
        }
        else if (arr[mid] > x) return  binarySearch(arr, l, mid - 1, x);
        else if (arr[mid] < x) return binarySearch(arr, mid + 1, h, x);
    }
    return -1;
}

int countSameNum(int arr[], int n, int pos, int x) {
    int count = 0, k = pos;
    while (arr[k] == x) {
        count++;
        k++;
    }
    k = pos - 1;
    while (arr[k] == x) {
        count++;
        k--;
    }
    return count;
}

int  countSum(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= 0) {
            int pos = binarySearch(arr, i + 1, n -1, -arr[i]);
            if (pos != 0)
                count += countSameNum(arr, n, pos, -arr[i]);
        }
    }
    return count;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int *arr1 = new int[n1 + 1];
    int *arr2 = new int[n2 + 1];
    
    int i, j;
    for (i = 0; i < n1; i++) cin >> arr1[i];
    for (j = 0; j < n2; j++) cin >> arr2[j];

    int *arr = merge(arr1, n1, arr2, n2);
    
    quickSortIncrease(arr, 0, n1 + n2 - 1);
    
    int count = countSum(arr, n1 + n2);

    cout << count << endl;

    return 0;
}