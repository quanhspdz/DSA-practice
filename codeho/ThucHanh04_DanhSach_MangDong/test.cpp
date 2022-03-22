#include <iostream>
using namespace std;

int main() {
    int size = 3;
    int *abc = new int[size];
    abc[0] = 1;
    abc[1] = 2;
    abc[2] = 3;
    
    int *abcd = new int[size + 1];
    abcd[0] = 1;
    abcd[1] = 2;
    abcd[2] = 3;
    abcd[3] = 4;

    abc = abcd;
    for (int i = 0; i < size + 1; i++) {
        cout << abc[i] << " ";
    }    

    cout << endl;
    return 0;
}