#include <iostream>
#include <string>
using namespace std;

int bruteForce(string des, string x) {
    int count = 0;
    int i, j;
    for (i = 0; i <= des.length() - x.length(); i++) {
        for (j = 0; j < x.length() && x[j] == des[i + j]; j++);
        if (j >= x.length()) 
            count++;
    }

    return count;
}

int main() {
    string des = "Quang anh dep trai ";
    string x = " ";

    int count = bruteForce(des, x);
    cout << count << endl;


    return 0;
}