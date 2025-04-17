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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int k = 0, sz = 0;
    vector<int> cnt(n, 0), ans(n, 0);
    for (int i = 1; i < n; i += 1) {
      if (a[i - 1] > 1) {
        k += (a[i - 1]);
        sz += 1;
        if (i + a[i - 1] - 1 < n) {
          cnt[i + a[i - 1] - 1] += 1;
        }
      }
      k -= sz;
      sz -= cnt[i];
      ans[i] += k;
    }
    k = 0, sz = 0;
    cnt.assign(n, 0);
    for (int i = n - 2; i >= 0; i -= 1) {
      if (a[i + 1] < -1) {
        // cout << a[i + 1] + 1 << '\n';
        k += (a[i + 1]);
        sz += 1;
        if (i + (a[i + 1] + 1) >= 0) {
          cnt[i + (a[i + 1] + 1)] += 1;
        }
      }
      k += sz;
      sz -= cnt[i];
      ans[i] += k;
    }
    int ret = 0;
    for (int i = 0; i < n; i += 1) {
      ret += (ans[i] + a[i] == 0);
    }
    cout << "Case #" << test_case << ": " << ret << '\n';
    test_case += 1;
  }
}