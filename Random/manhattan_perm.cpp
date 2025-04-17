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
    int tot = 0;
    for (int i = 0; i < n; i += 1) {
      tot += abs(n - 1 - i * 2);
    }
    if (k & 1 || k > tot) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    int multiplier = 0;
    for (int i = 1; i <= n && k > 0; i += 1) {
      if (k >= (n - (1 + multiplier)) * 2) {
        k -= (n - (1 + multiplier)) * 2;
        swap(ans[i - 1], ans[n - i]);
      } else {
        swap(ans[i - 1], ans[i - 1 + k / 2]);
        break;
      }
      multiplier += 2;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}
