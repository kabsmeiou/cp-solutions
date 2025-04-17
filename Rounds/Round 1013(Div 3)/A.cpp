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
    vector<int> need{3, 1, 2, 1, 0, 1};
    int i = 0;
    bool ok = false;
    for (i; i < n; i += 1) {
      if (a[i] <= 5) need[a[i]] -= 1;
      bool temp = true;
      for (auto x : need) {
        if (x > 0) {
          temp = false;
          break;
        }
      }
      if (temp) {
        ok = true;
        break;
      }
    }
    cout << (ok ? i + 1 : 0) << '\n';
  }
}