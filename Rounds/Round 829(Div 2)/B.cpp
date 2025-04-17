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
    for (int i = (n + 1) / 2 + (n % 2 == 0); i <= n; i++) {
      cout << i << ' ';
      if (i != n || n % 2 == 0) {
        cout << i - (n + 1) / 2 + (n & 1) << ' ';
      }
    }
    cout << '\n';
  }
}