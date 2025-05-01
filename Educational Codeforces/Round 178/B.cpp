#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &c : a) cin >> c;
    vector<int64_t> pref_max(n + 1, 0);
    for (int i = 1; i <= n; i += 1) {
      pref_max[i] = max(pref_max[i - 1], a[i - 1]);
    }
    vector<int64_t> suf_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i -= 1) {
      suf_sum[i] = suf_sum[i + 1] + a[i];
    }
    for (int i = n; i >= 1; i -= 1) {
      int64_t change = max(pref_max[i], a[i - 1]);
      if (change == a[i - 1]) {
        cout << suf_sum[i - 1] << ' ';
      } else {
        cout << pref_max[i] + suf_sum[i - 1] - a[i - 1] << ' ';
      }
    }
    cout << '\n';
  }
}