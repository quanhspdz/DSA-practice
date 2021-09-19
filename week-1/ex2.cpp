#include <iostream>
using namespace std;

int sumOfElement(long n) {       //n <= 10^7
    int sum = 0;
    int divider = 10;
    while (n  > 0) {
        sum+= n % divider;
        n /= divider;
    }
    return sum;
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    int position = low, partitonVale = sumOfElement(arr[high]);

    for (int j = low; j < high; j++) {
        int sumOfArrJ = sumOfElement(arr[j]);
        if (sumOfArrJ < partitonVale || (sumOfArrJ == partitonVale && arr[j] < arr[high])) {
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

void bubbleSortElement(long arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            int sumOfE1 = sumOfElement(arr[j]);
            int sumOfE2 = sumOfElement(arr[j + 1]);
            if (sumOfE1 > sumOfE2) {
                long tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            else if (sumOfE1 == sumOfE2 && arr[j] > arr[j + 1]) {
                    long tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    //cout << sumOfElement(n) << endl;
    int *arr = new int[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSortIncrease(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;;
    }
    
    return 0;
}