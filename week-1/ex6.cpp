#include<iostream>
using namespace std;

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

void findTheCouple(int arr[], int n, int k) {
    int i, outPutI = - 1, outPutJ = -1;
    int loop = 0;
    for (i = n - 1; i > 0; i--) {
        if (arr[i] <= k) {
            loop = i + 1;
            break;
        }
    }

    for (i = 0 ; i < loop - 1; i++) {
        int pos = -1;
        pos = binarySearch(arr, i + 1, loop, k - arr[i]);
        if (pos != -1) {
            outPutI = i;
            outPutJ = pos;
        }
    }
    while (arr[outPutJ - 1] == k - arr[outPutI]) {
        outPutJ--;
    } 

    if (outPutI != -1 && outPutJ != -1) {
        cout << ++outPutI << " " << ++outPutJ << endl;
    }
    else cout << -1 << endl;

}

int main() {   
    int n, k;
    cin >> n >> k;
    int i;
    int *arr = new int[n + 1];
    for (i = 0; i < n; i++) cin >> arr[i];

    findTheCouple(arr, n, k);



    return 0;
}