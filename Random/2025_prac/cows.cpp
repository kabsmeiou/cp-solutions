#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      vector<int> a(n);
      for (auto &c : a) cin >> c;
      int cow = a[k - 1];
      int index = n;
      for (int i = 0; i < n; i += 1) {
         if (a[i] > cow) {
            index = i;
            break;
         }
      }
      if (index >= k - 1) {
         cout << index - 1 << '\n';
         continue;
      }
      int swap_ans = 0;
      for (int i = index + 1; i < n && cow > a[i]; i += 1) {
         swap_ans += 1;
      }
      swap_ans += (index >= 1);
      cout << max(swap_ans, index - 1) << '\n';
   }
}