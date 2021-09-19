#include <iostream>
using namespace std;

void selectionSortIncreased(int arr[], int n) {
    int pos = 1, min, temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        min = arr[i];
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        }
        if (pos != i) {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
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

    selectionSortIncreased(arr, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}