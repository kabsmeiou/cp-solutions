#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == 'A' && s[n - 1] == 'A') {
      cout << "Alice" << '\n';
      continue;
    } else if (s[0] == 'B' && s[n - 1] == 'B') {
      cout << "Bob" << '\n';
      continue;
    }
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i += 1) {
      if (s[i] == 'A') {
        cnt_a += 1;
      } else {
        cnt_b += 1;
      }
    }
    if (s[0] == 'A' && cnt_b == 1) {
      cout << "Alice" << '\n';
    } else if (s[0] == 'B' && cnt_a == 1) {
      cout << "Bob" << '\n';
    } else if (s[0] == 'B' && cnt_a > 1) {
      cout << (s[n - 2] == 'A' ? "Alice" : "Bob") << '\n';
    } else {
      cout << "Bob" << '\n';
    }
  }
}