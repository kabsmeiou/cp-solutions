#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n, x;
    cin >> n >> x;
    int64_t save = x;
    if (x == 0 && n == 1) {
      cout << -1 << '\n';
      continue;
    }
    int bits = 0;
    int64_t ans = 0;
    vector<bool> activated(31, 0);
    for (int i = 30; i >= 0; i -= 1) {
      int64_t take = (1 << i);
      // cout << take << ' ' << '\n';
      if (x - take >= 0) {
        ans += take;
        x -= take;
        activated[i] = 1;
        bits += 1;
      }
    }
    if (bits < n) {
      int64_t need = n - bits;
      ans += need;
      // cout << '\n';S
      //cout << need << ' ' << 'x' << '\n';
      if (need & 1) {
        bool ok = false;
        for (int i = 1; i < 31; i += 1) {
          ok |= activated[i];
        }
        ans += (ok ? 1 : 3);
      }
    }
    cout << ans << '\n';
  }
}