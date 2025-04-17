#include <bits/stdc++.h>
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
    if (n == 2) {
      cout << min(a[0], a[1]) << '\n';
      continue;
    }
    int ans = -1;
    for (int i = 1; i < n - 1; i += 1) {
      int temp[] = {a[i - 1], a[i], a[i + 1]};
      if (temp[0] > temp[1]) swap(temp[0], temp[1]);
      if (temp[1] > temp[2]) swap(temp[1], temp[2]);
      if (temp[0] > temp[1]) swap(temp[0], temp[1]);
      ans = max(ans, temp[1]);
    }
    cout << ans << '\n';
  }
} 