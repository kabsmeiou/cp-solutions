#include <bits/stdc++.h>
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
    int minimum = 1e9;
    for (auto &c : a) cin >> c, minimum = min(minimum, c);
    bool ok = true;
    int ans = 0;
    for (int i = 0; i < n; i += 1) {
      if (a[i] == minimum) {
        ans = i;
        int prev = a[i];
        i += 1;
        while (i < n) {
          ok &= a[i] >= prev;
          prev = a[i];
          i += 1;
        }
      }
    }
    cout << (ok ? ans : -1) << '\n';
  }
}