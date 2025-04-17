#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int lst = 0;
    vector<int> ans(n, 1);
    for (int i = 1; i < n - 1; i += 1) {
      bool ascending = a[i + 1] >= a[i] && a[lst] <= a[i];
      bool descending = a[i + 1] <= a[i] && a[lst] >= a[i];
      if (ascending || descending) {
        ans[i] = 0;
        continue;
      }
      lst = i;
    }
    int res = accumulate(ans.begin(), ans.end(), 0LL);
    if (res == 2 && a[0] == a[n - 1]) res = 1;
    cout << res << '\n';
  }
}