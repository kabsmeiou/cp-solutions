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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i += 1) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i += 1) {
      cin >> b[i];
    }
    vector<int> vis(n + 1, 0);
    int ans = 0, lst = 0;
    for (int i = 0; i < n; i += 1) {
      int to_rep = a[b[i] - 1];
      // cout << to_rep << '\n';
      // cout << b[i] << '\n';
      if (!vis[b[i]]) {
        ans += 1;
        vis[b[i]] = 1;
        int nxt = to_rep - 1;
        // cout << nxt << '\n';
        while (!vis[nxt + 1]) {
          ans += 1;
          vis[nxt + 1] = 1;
          nxt = a[nxt] - 1;
        }
      }
      cout << ans << " \n"[i == n - 1];
    }
  }
}