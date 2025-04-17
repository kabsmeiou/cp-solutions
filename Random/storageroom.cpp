#include <bits/stdc++.h>
#define int long long
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        std::cin >> a[i][j];
      }
    }
    bool good = true;
    for (int i = 0; i < n - 1; i += 1) {
      bool ok = true, non_zero = false;
      for (int j = i; j < n; j += 1) {
        if (a[i][j] != a[j][i]) {
          ok = false;
          break;
        }
        if (a[i][j] || a[j][j]) non_zero = true;
      }
      if (!ok || !non_zero) {
        good = false;
        break;
      }
    }
    if (!good) {
      std::cout << "NO" << '\n';
      continue;
    }
    const int mx = (1 << 30) - 1;
    std::vector<int> ans(n, mx);
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        if (i != j) {
          ans[i] &= a[i][j];
          ans[j] &= a[i][j];
        }
      }
    }
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        if ((ans[i]|ans[j]) != a[i][j] && i != j) {
          good = false;
          break;
        }
      }
    }
    std::cout << "YES" << '\n';
    for (int i = 0; i < n; i += 1) {
      std::cout << ans[i] << " \n"[i == n - 1];
    }
  }
}