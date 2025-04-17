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
    if (n == 1) {
      if (a[0] == 0) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        cout << 1 << '\n';
      } else {
        cout << -1 << '\n';
      }
      continue;
    }
    int cur = 0, alt = 1, cnt = 0, len = 0, ind_first = -1, ind_last = -1, tot = 0;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i += 1) {
      tot += a[i - 1];
      len += 1;
      cur += (alt ? a[i - 1] : -a[i - 1]);
      if (a[i - 1] != 0) {
        cnt += 1;
        if (cnt == 1) {
          ind_first = i - len;
        } else {
          ind_last = i - 1;
        }
      }
      alt = (alt ^ 1 || cnt == 2);
      if (cnt == 2) {
        if (cur == 0) {
          ans.push_back({i - len + 1, i});
        } else if (len % 2 == 0) {
          ans.push_back({i - len + 1, i - 1});
          ans.push_back({i, i});
        } else {
          if (a[ind_first] == 0) {
            ans.push_back({i - len + 1, i - len + 1});
            ans.push_back({i - len + 2, i - 1});
            ans.push_back({i, i});
          } else {
            ans.push_back({i - len + 1, i - len + 1});
            ans.push_back({i - len + 2, i});
          }
        }
        ind_first = -1, ind_last = -1;
        cnt = 0;
        len = 0;
        cur = 0;
      }
    }
    if (tot & 1) {
      cout << -1 << '\n';
      continue;
    }
    if (ans.empty()) {
      if (cur != 0) {
        cout << -1 << '\n';
      } else {
        cout << 2 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 2 << ' ' << n << '\n';
      }
      continue;
    }
    pair<int, int> lst = ans.back();
    if (lst.second < n) {
      ans.push_back({lst.second + 1, n});
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
      cout << l << ' ' << r << '\n';
    }
  }
}