#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((c - (b - a)) >= b && (c - (b - a) - b) % 3 == 0 ? "YES" : "NO") << '\n';
  }
}