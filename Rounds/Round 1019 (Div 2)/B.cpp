#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, switches = 0;
    char lst = '0';
    for (int i = 0; i < n; i += 1) {
      ans += 1;
      if (s[i] != lst) {
        ans += 1;
        switches += 1;
      }
      lst = s[i];
    }
    if (switches >= 3) {
      ans -= 2;
    } else if (switches == 2) {
      ans -= 1;
    }
    cout << ans << '\n';
  }
}