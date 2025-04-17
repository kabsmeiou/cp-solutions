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
    vector<int> t(n), p(n);
    for (auto &c : p) cin >> c;
    for (auto &c : t) cin >> c;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      a.push_back(p[i] + t[i]);
      a.push_back(p[i] - t[i]);
    }
    int l = 1e8, r = -1;
    for (int i = 0; i < 2 * n; i += 1) {
      l = min(l, a[i]);
      r = max(r, a[i]);
    }
    int ans = l + r;
    cout << ans / 2 << (ans & 1 ? ".5" : "") << '\n';
  }
}