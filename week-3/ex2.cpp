#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n1, n2, x;
    cin >> n1 >> n2 >> x;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) 
        cin >> arr1[i];
    for (int i = 0; i < n2; i++) 
        cin >> arr2[i];

    stack<int> stack1;
    stack<int> stack2;
    for (int i = n1 - 1; i >= 0; i--) {
        stack1.push(arr1[i]);
    }
    for (int i = n2 - 1; i >= 0; i--) {
        stack2.push(arr2[i]);
    }

    stack<int> stackTmp1;
    stack<int> stackTmp2;
    long long int sum1 = 0;
    while (!stack1.empty() && sum1 + stack1.top() <= x) {
        stackTmp1.push(stack1.top());
        sum1 += stack1.top();
        stack1.pop();
    }
    long long int sum2 = 0;
    while (!stack2.empty() && sum2 + stack2.top() <= x) {
        stackTmp2.push(stack2.top());
        sum2 += stack2.top();
        stack2.pop();
    }

    long long int S = sum1 + sum2;
    int score = stackTmp1.size() + stackTmp2.size();
    while (SUM > x) {
        if (!stackTmp1.empty() && !stackTmp2.empty()) {
            if (stackTmp1.top() > stackTmp2.top()) {
                SUM -= stackTmp1.top();
                score--;
                stackTmp1.pop();
            } 
            else {
                SUM -= stackTmp2.top();
                score--;
                stackTmp2.pop();
            }
        }
        else {
            if (stackTmp2.empty()) {
                SUM -= stackTmp1.top();
                score--;
                stackTmp1.pop();
            }
            else if (stackTmp1.empty()){
                SUM -= stackTmp2.top();
                score--;
                stackTmp2.pop();
            }
        }
    }

    cout << score << endl;

    return 0;
}