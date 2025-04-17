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
    if (n % 2 == 0) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = n; i >= 1; i -= 1) {
      cout << i << " \n"[i == n];
    }
  }
}
