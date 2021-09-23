#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int i = 0, j = 0, k;
    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

}
void mergeSortIncreased(int arr[], int l, int h) {
    if (l < h) {
        int m = l + (h - l) / 2;
        mergeSortIncreased(arr, l, m);
        mergeSortIncreased(arr, m + 1, h);
        merge(arr, l, m, h);
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

    mergeSortIncreased(arr, 0, n - 1);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}