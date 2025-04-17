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
    int ans = a[n - 1];
    for (int i = n - 2; i >= 0; i -= 1) {
      if (a[i] <= ans) {
        ans += 1;
        continue;
      }
      ans = max(a[i], ans);
    }
    cout << ans << '\n';
  }
}