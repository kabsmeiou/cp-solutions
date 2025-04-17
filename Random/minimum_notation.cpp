#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    char lst = s[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] - '0' <= lst - '0') {
        lst = s[i];
        continue;
      }
      s[i] = min(char(s[i] + 1), '9');
    }
    sort(s.begin(), s.end());
    cout << s << '\n';
  }
} 