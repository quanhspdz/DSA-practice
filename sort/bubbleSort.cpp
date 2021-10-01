#include <iostream>
using namespace std;

void bubbleSortIncreased(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]= ";
        cin >> arr[i];
    }

    bubbleSortIncreased(arr, n);

    cout << "Mang sau khi sap xep tang dan: ";
    for (i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}