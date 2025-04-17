#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a;
    int cur = 0;
    for (int i = 0; i < n; i += 1) {
      int k;
      cin >> k;
      if (k >= x) {
        cur += 1;
        continue;
      }
      a.push_back(k);
    }
    sort(a.rbegin(), a.rend());
    int lst = 1e9, sz = 0;
    for (int i = 0; i < a.size(); i += 1) {
      lst = min(lst, a[i]);
      sz += 1;
      if (sz * lst >= x) {
        lst = 1e9;
        sz = 0;
        cur += 1;
      }
    }
    cout << cur << '\n';
  }
}