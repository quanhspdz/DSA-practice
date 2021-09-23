#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b, int *c, int *d) {
    int tmp1, tmp2;
    tmp1 = *a;
    tmp2 = *b;
    *a = *c;
    *b = *d;
    *c = tmp1;
    *d = tmp2;
}

int partition(int arr[], int arr2[], int low, int high) {
    int position = low, partitonVale = arr[high];

    for (int j = low; j < high; j++) {
        if (arr[j] < partitonVale) {
            swap(&arr[j], &arr2[j], &arr[position], &arr2[position]);
            position++;
        }
    }
    swap(&arr[position], &arr2[position], &arr[high], &arr2[high]);
    return (position);
}

void quickSortIncrease(int arr[], int arr2[], int low, int high) {
    if (low < high) {
        int p = partition(arr, arr2, low, high);
        quickSortIncrease(arr, arr2, low, p - 1);
        quickSortIncrease(arr, arr2,  p + 1, high);
    }
}

bool check(int a, int b, int c, int d) {  
    if (b < c || d < a) return false;
    return true;
}

void combineElement(int arr1[], int arr2[], int n) {
    int i, j;
    int *doneArr = new int[n];
    for (i = 0; i < n; i++) {
        doneArr[i] = 0;
    }
    
        i = 0;
        int min = arr1[i];
        int max = arr2[i];
        for (j = 1; j < n; j++) {
            if (doneArr[j] == 0 && check(min, max, arr1[j], arr2[j])) {
                min = (min <= arr1[j]) ? min : arr1[j];
                max = (max >= arr2[j]) ? max : arr2[j];
                doneArr[j] = 1;
            }
            else if (!check(min, max, arr1[j], arr2[j])) {
                cout << min << " " << max << endl;
                min = arr1[j];
                max = arr2[j];
                doneArr[j] = 1;
            }
        }

    if (doneArr[n - 1] == 0) {
        cout << arr1[n - 1] << " " << arr2[n - 1] << endl;
    }
    else {
        cout << min << " " << max << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i] >> arr2[i];
    }

    quickSortIncrease(arr1, arr2, 0, n - 1);

    combineElement(arr1, arr2, n);

    return 0;
}