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
    string s;
    cin >> n >> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[s[i] - 'a'] += 1;
    }
    int ans = 0;
    for (auto [_, c] : mp) ans = max(c, ans);
    cout << (ans >= n / 2 + 1 ? n - (n - ans) * 2 : (n & 1)) << '\n';
  }
}