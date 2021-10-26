#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int tong(stack<int> a) {
	int sum=0;
	for(int i = 0; i < 2; i++)
	{
		sum+=a.top();
		a.pop();
	}
	return sum;
}

int main() {
	int n,result = 0;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	stack <int>  a;

	for (int i = 0; i < n; i++)
	{

		if(arr[i] == "+") {
			int temp = tong(a);
			a.push(temp);
		} else if (arr[i] == "C") {
			a.pop();
		} else if (arr[i] == "D") {
			int temp = 2 * a.top();
			a.push(temp);
		} else {
			stringstream stream(arr[i]);
            int x = 0;
            stream >> x;
			a.push(x);
		}
	}
	 while (a.empty() == false)  {
          result+=a.top();
          a.pop();
     }
     cout << result << endl;
     return 0;
}