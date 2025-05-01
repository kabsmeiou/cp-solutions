#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n <= 3) {
      cout << n << '\n';
    } else {
      int64_t ans = n / 2;
      cout << (n & 1 ? ans * ans + ans + 1 : ans * ans + 1) << '\n';
    }
  }
}