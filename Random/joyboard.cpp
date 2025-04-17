#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 3) {
      cout << 0 << '\n';
      continue;
    }
    if (k == 1) {
      cout << 1 << '\n';
    } else if (k == 2) {
      int ans = m <= n ? m : n + (m - n) / n;
      cout << ans << '\n';
    } else {
      int ans = m <= n ? 0 : m - n - (m - n) / n;
      cout << ans << '\n';
    }
  }
}