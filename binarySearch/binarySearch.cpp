#include <iostream>
using namespace std;


int binarySearch(int arr[], int l, int h, int x, int &firstPos, int &time) {
    if (l <= h) {
        int mid = l + (h - l) / 2;
        if (x == arr[mid]) {
            time++;
            if (mid - 1 >= 0) {
                if (arr[mid - 1] == x) {
                    binarySearch(arr, l, mid - 1, x, firstPos, time);
                } 
                else firstPos = mid;
            }
            if (mid + 1 <= h) {
                if (arr[mid + 1] == x) {
                    binarySearch(arr, mid + 1, h, x, firstPos, time);
                }
            }
                
            return mid;
        }
        else if (arr[mid] > x) return  binarySearch(arr, l, mid - 1, x, firstPos, time);
        else if (arr[mid] < x) return binarySearch(arr, mid + 1, h, x, firstPos, time);
    }
    return -1;
}

int binarySearchUsingWhile(int arr[], int l, int h, int x) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (x < arr[mid]) {
            h = mid - 1;
        }
        else if (x > arr[mid]) {
            l = mid + 1;
        }
        else return mid;
    }
    return -1;
}
 
int main() {
    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 9,
                    9, 9, 9, 9, 15, 16, 17, 19, 19, 19};
    int x;
    cout << "Nhap so can tim: ";
    cin >> x;
    
    int firstPos = -1, time = 0;
    int result = binarySearch(arr, 0, 19, x, firstPos, time);
    if (result != -1) {
        cout << "Da tim duoc " << x << endl <<
                "Xuat hien  tai vi tri " << firstPos << endl <<
                "So lan xuat hien: " << time << endl;
    }
    else cout << "Khong tim thay " << x << "!" << endl;


    return 0;
}