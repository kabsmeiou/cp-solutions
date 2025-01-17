#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int unique_cnt = 0, cnt = 0;
    for (int i = 0; i < n; i += 1) {
      if (f - 1 == i) continue;
      unique_cnt += (a[i] > a[f - 1]);
      cnt += (a[i] >= a[f - 1]);
    }
    if (unique_cnt >= k) {
      cout << "NO" << '\n';
    } else if (cnt >= k) {
      cout << "MAYBE" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}