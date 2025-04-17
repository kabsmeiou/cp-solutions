#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i += 1) {
        cout << i << '\n';
      }
      continue;
    }
    if ((n * k / 2) % k == 0) {
      cout << "YES" << '\n';
      int x = 2;
      for (int i = 0; i < n / 2; i += 1) {
        for (int j = 0; j < k; j += 1) {
          cout << x << ' ';
          x += 2;
        }
        cout << '\n';
      }
      int y = 1;
      for (int i = 0; i < n / 2; i += 1) {
        for (int j = 0; j < k; j += 1) {
          cout << y << ' ';
          y += 2;
        }
        cout << '\n';
      }
      continue;
    }
    cout << "NO" << '\n';
  }
} 