#include <bits/stdc++.h>
#define int long long 
using namespace std;
int MAX_LL = 1e18;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> pref(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i += 1) {
      pref[i] = a[i - 1] + pref[i - 1];
    }
    for (int i = 1; i <= n; i += 1) {
      int l = 1, r = k;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (pref[n] * mid - pref[i - 1] >= x) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      // cout << ((k + 1) - l) << '\n';
      ans += ((k + 1) - l);
    }
    cout << ans << '\n';
  }
}