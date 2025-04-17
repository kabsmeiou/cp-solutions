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
    vector<int> a(n);
    map<int, int> mp;
    for (auto &c : a) cin >> c, mp[c] += 1;
    int ans = 0;
    for (auto c : mp) {
      ans += min(c.second, mp[k - c.first]);
    }
    cout << ans / 2 << '\n';
  }
}