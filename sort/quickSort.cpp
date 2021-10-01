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

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap arr[" << i << "]= ";
        cin >> arr[i];
    }

    quickSortIncrease(arr, 0, n - 1);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}