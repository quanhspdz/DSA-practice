#include <iostream>
using namespace std;

void merge(int arr[], int l1, int h1, int l2, int h2) {
    int n1 = h1 - l1 + 1;
    int n2 = h2 - l2 + 1;
    int *L = new int[n1];
    int *R = new int[n2];

    int i, j;
    for (i = 0; i < n1; i++) {
        L[i] = arr[l1 + i];
    } 
    for (j = 0; j < n2; j++) {
        R[j] = arr[l2 + j];
    }

    int currentPos = l1;
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

void mergeSortLoop (int arr[], int n) {
    int elementNum = 1, i;
    int groupNum;
    while (elementNum < n) {
        if (n % elementNum != 0) groupNum = n / elementNum + 1;
        else groupNum = n / elementNum;
        
        for (i = 0; i + 1 < groupNum; i+=2) {
            int l1 = i * elementNum;
            int h1 = l1 + elementNum - 1;
            int l2 = (i + 1) * elementNum;
            int h2 = l2 + elementNum - 1;
            merge(arr, l1, h1, l2, h2);
        }

        elementNum++;
    }
}

int main() {
    int n = 10;
    int arr[n] = {38, 27, 43, 3, 9, 82, 10, -6969, 123645, 9696};

    mergeSortLoop(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}