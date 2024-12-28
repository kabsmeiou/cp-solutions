#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    int cnt = 0, x = 1;
    while (x << 1 <= r) {
      cnt += 1;
      x <<= 1;
    }
    cout << cnt << '\n';
  }
}