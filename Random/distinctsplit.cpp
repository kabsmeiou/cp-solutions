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
    int ans = 0;
    vector<int> a(26, 0), b(26, 0);
    for (int i = 0; i < n; i += 1) {
      a[s[i] - 'a'] += 1;
    }
    for (int i = 0; i < n; i += 1) {
      a[s[i] - 'a'] -= 1;
      b[s[i] - 'a'] += 1;
      int cur = 0;
      for (int j = 0; j < 26; j += 1) {
        cur += (a[j] > 0) + (b[j] > 0);
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}