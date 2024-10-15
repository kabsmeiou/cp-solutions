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
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 1; i < n; i += 1) {
      if (s[i - 1] > s[i]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';  
  }
}