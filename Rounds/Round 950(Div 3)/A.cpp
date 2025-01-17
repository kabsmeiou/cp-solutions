#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int n, m;
    cin >> n >> m >> s;
    map<char, int> mp;
    string rounds = "ABCDEFG";
    for (int i = 0; i < 7; i += 1) {
      mp[rounds[i]] = 0;
    }
    for (int i = 0; i < n; i += 1) {
      mp[s[i]] += 1;
    }
    int ans = 0;
    for (int i = 0; i < 7; i += 1) {
      if (mp[rounds[i]] < m) ans += (m - mp[rounds[i]]);
    }
    cout << ans << '\n';
  }
}