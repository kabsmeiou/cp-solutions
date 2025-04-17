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
    int ind_1, ind_2, ind_n;
    for (int i = 0; i < n; i += 1) {
      cin >> a[i];
      if (a[i] == 1) {
        ind_1 = i + 1;
      }
      if (a[i] == 2) {
        ind_2 = i + 1;
      }
      if (a[i] == n) {
        ind_n = i + 1;
      }
    }
    if ((ind_1 < ind_n && ind_n < ind_2) || ((ind_2 < ind_n && ind_n < ind_1))) {
      cout << 1 << ' ' << 1 << '\n';
      continue;
    }
    if (abs(ind_1 - ind_n) < abs(ind_2 - ind_n)) {
      cout << ind_1 << ' ' << ind_n << '\n';
    } else {
      cout << ind_2 << ' ' << ind_n << '\n';
    }
  }
} 