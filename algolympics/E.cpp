#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  int test_case = 1;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i += 1) {
      int s, h;
      cin >> s >> h;
      a[i] = {s, h};
    }
    vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(n + 1));
    dp[0][0] = dp[1][0] = {0, 0};
    for (int i = 1; i <= n; i += 1) {
      dp[0][i] = {0, dp[1][i - 1].second};
      int ok = false;
      pair<int, int> from_bottom = dp[1][i - 1];
      if (a[i - 1].first + dp[1][i - 1].first <= m) {
        from_bottom = {(a[i - 1].first + dp[1][i - 1].first), (a[i - 1].second + dp[1][i - 1].second)};
        ok = true;
      }
      pair<int, int> from_top_corner = {0, 0};
      if (a[i - 1].first + dp[0][i - 1].first <= m) {
        from_top_corner = {(a[i - 1].first + dp[0][i - 1].first), (dp[0][i - 1].second + a[i - 1].second)};
        ok = true;
      }
      pair<int, int> prev = {0, 0};
      if (i >= 2 && a[i - 2].first + a[i - 1].first <= m) {
        prev = {(a[i - 1].first + a[i - 2].first), (dp[0][i - 2].second + a[i - 1].second + a[i - 2].second)};
        ok = true;
      }
      // if all greater than m, then have to skip
      if (!ok) {
        dp[1][i] = {0, from_bottom.second};
        continue;
      }
      dp[1][i] = max({from_bottom, from_top_corner, prev}, [](auto &x, auto &y) {
        return x.second < y.second;
      });
    }
    int ans = -1;
    for (int i = 0; i <= n; i += 1) {
      ans = max({dp[0][i].second, dp[1][i].second, ans});
    }
    cout << "Case #" << test_case << ": " << ans << '\n';
    test_case += 1;
  }
}