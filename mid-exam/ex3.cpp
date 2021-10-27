#include <iostream>
#include <algorithm>
using namespace std;

double medianOfArray(int arr[], int n) {
    sort(arr, arr + n);
    int mid = n / 2;
    double result;
    if (n % 2 == 0) {
        return (double) (arr[mid] + arr[mid - 1]) / 2;
    } else {
        return (double) arr[mid];
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%0.1lf\n", medianOfArray(arr, i+ 1));
    }

    return 0;
}