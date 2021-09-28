#include <iostream>
using namespace std;

int hIdex(int arr[], int n) {
    int count[n + 1];
    for (int i = 0; i < n + 1; i++)   
            count[i] = 0;

    for(int i = 0; i < n; i++){
        int value = arr[i];
        if(value >= n){
            count[n]++;
        } else {
            count[value]++;
        }
    }
    
    int sumCount = 0;
    for(int i = n; i >= 0; i--){
        sumCount += count[i];
        if(sumCount >= i) return i;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << hIdex(arr, n) << endl;

    return 0;
}
