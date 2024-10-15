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
    vector<int> a(n), b(n + 1);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    int ans = 0, k = b.back(), ideal = 1e9;
    bool ok = false;
    for (int i = 0; i < n; i += 1) {
      if ((k >= a[i] && k <= b[i]) || (k <= a[i] && k >= b[i])) {
        ok = true;
      }
      ideal = min({abs(k - a[i]), abs(k - b[i]), ideal});
      ans += abs(a[i] - b[i]);
    }
    // cout << maximum << ' ' << minimum << ' ' << k << '\n';
    if (!ok) {
      cout << ans + ideal + 1 << '\n';
    } else {
      cout << ans + 1 << '\n';
    }
  } 
}