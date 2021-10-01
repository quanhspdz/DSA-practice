#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;
    int *L = new int[n1];
    int *R = new int[n2];
    int i, j;
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int currentPos = l;
    i = 0;
    j = 0;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[currentPos++] = L[i++];
        }
        else {
            arr[currentPos++] = R[j++];
        }
    }

    while (i < n1) {
        arr[currentPos++] = L[i++];
    }
    while (j < n2) {
        arr[currentPos++] = R[j++];
    }

    delete(L);
    delete(R);
}

void mergeSortRecursive(int arr[], int l, int h) {
    if (l < h) {
        int m = l + (h - l) / 2;
        mergeSortRecursive(arr, l, m);
        mergeSortRecursive(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int main() {
    int n = 7;
    int arr[n] = {38, 27, 43, 3, 9, 82, 10};

    mergeSortRecursive(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}