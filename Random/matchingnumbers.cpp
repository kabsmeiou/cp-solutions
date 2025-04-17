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
      cout << "NO\n";
      continue;
    }
    if (n == 1) {
      cout << "YES\n";
      cout << "1 2\n";
      continue;
    }
    cout << "YES\n";
    int need = n * 2 - (n / 2 - 1);
    for (int i = 1; i <= n; i += 1, need += 1) {
      cout << i << ' ' << need << '\n';
      if (need == n * 2) {
        need = n;
      }
    }
  }
}