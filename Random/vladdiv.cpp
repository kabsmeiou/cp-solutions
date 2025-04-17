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
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int mask = (1 << 31) - 1;
    int lim = 1073741824;
    // how to compare each of them? it has to be equal to "mask"
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i += 1) {
      if (a[i] >= lim) {
        mp[a[i]] += 1;
      }
    }
    for (int i = 0; i < n; i += 1) {
      int convert = a[i] ^ mask;
      if (mp[convert]) {
        mp[convert] -= 1;
        continue;
      }
      ans += 1;
    }
    cout << ans << '\n';
  }
}