#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int hIndex(int c[], int n) {
      int bucket[n + 1];
        for (int i = 0; i < n + 1; i++)   
            bucket[i] = 0;

      for(int i = 0; i < n; i++){
         int x = c[i];
         if(x >= n){
            bucket[n]++;
         } else {
            bucket[x]++;
         }
      }
      int cnt = 0;
      for(int i = n; i >= 0; i--){
         cnt += bucket[i];
         if(cnt >= i) return i;
      }
      return -1;
   }
};
int main(){
   Solution ob;

   int n;
    cin >> n;
   int *v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

   cout << (ob.hIndex(v, n)) << endl;

   return 0;
}
