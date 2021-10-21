#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    map<int, int> count;

    while (n > 0) {
        n--;
        cin >> num;
        if (count.find(num) == count.end()) {
            count[num] = 1;
        } else {
            count[num]++;
        }
        cout << count[num] << endl;
    }

    return 0;
}