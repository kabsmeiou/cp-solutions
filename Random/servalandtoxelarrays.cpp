#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), lst(n, 0);
    map<int, int> cnt;
    for (auto &c : a) cin >> c, cnt[c] = 1;
    for (int i = 1; i <= m; i += 1) {
      int p, v;
      cin >> p >> v, p--;
      cnt[v] += 1;
      cnt[a[p]] += (i - lst[p] - 1);
      lst[p] = i;
      a[p] = v;
    }
    for (int i = 0; i < n; i += 1) {
      cnt[a[i]] += (m - lst[i]);
    }
    int ans = 0;
    for (auto [_, c] : cnt) {
      int not_found = m - c;
      ans += m * (m + 1) / 2 - not_found * (not_found + 1) / 2;
    }
    cout << ans << '\n';
  }
}