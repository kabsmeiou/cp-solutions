#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &c : a) cin >> c, ++cnt[c];
    int64_t ans = 0;
    for (auto [x, c] : cnt) {
      if (x == 1 || x == 2) continue;
      ans += 1LL * c * (c - 1) / 2;
    }
    int combined = cnt[1] + cnt[2];
    ans += 1LL * combined * (combined - 1) / 2;
    cout << ans << '\n';
  }
}