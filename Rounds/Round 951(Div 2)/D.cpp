#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i += 1) 
      pref[i + 1] = pref[i] + (s[i] == '1');
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i -= 1) {
      int j = min(n, i + k);
      dp[i] = dp[j] && (pref[j] - pref[i] == j - i || pref[j] - pref[i] == 0) && (j == n || s[i] != s[j]);
      if (dp[i]) cout << i << ' ' << j << '\n';
    }
    for (auto i : dp) {
      cout << i << ' ';
    }
  }
}
