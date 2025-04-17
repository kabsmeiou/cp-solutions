#include <bits/stdc++.h>
#define int long long
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    int ans = a * n;
    if (b > a) {
      int x = (b - a) >= n ? (b - n) : a;
      int extra = n - (b - a) > 0 ? n - (b - a) : 0;
      ans = std::max((b * (b + 1)) / 2 - (x * (x + 1)) / 2 + extra * a, ans);
    }
    std::cout << ans << '\n';
  }
}