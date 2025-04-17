#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, m;
    cin >> n >> m >> k;
    int l = 1, r = m;
    while (l < r) {
      int mid = (l + r) >> 1;
      int x = mid + 1;
      if ((m / x * mid + m % x) * n >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l << '\n';
  }
}