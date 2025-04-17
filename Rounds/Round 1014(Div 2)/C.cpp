#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int ans = 0, cnt = 0, ok = 0;
    for (int i = 0; i < n; i += 1) {
      ans += a[i];
      cnt += (a[i] & 1);
      ok |= (a[i] % 2 == 0);
    }
    if (!ok || !cnt) {
      cout << *max_element(a.begin(), a.end()) << '\n';
      continue;
    }
    cout << ans - cnt + 1 << '\n';
  }
}