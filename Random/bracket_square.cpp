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
    string s;
    cin >> n >> s;
    int ops = 0;
    int l = 0;
    while (l + 1 < n) {
      if (s[l] == '(') {
        l += 2;
      } else {
        int r = l + 1;
        if (s[r] == ')') {
          ops += 1;
          l += 2;
          continue;
        }
        while (r < n && s[r] != ')') {
          r += 1;
        }
        if (r == n) {
          break;
        }
        l = r + 1;
      }
      ops += 1;
    }
    cout << ops << ' ' << n - l << '\n';
  }
}