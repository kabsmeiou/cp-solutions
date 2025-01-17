#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, bool> bcnt;
    for (int i = 0; i < n; i += 1) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i += 1) {
      cin >> b[i];
      bcnt[b[i]] = true;
    }

    int m;
    cin >> m;
    vector<int> d(m);
    map<int, int> dcnt;
    
    bool ok = true;
    for (int i = 0; i < m; i += 1) {
      cin >> d[i];
      dcnt[d[i]] += 1;
    }

    if (!bcnt[d.back()]) {
      cout << "NO" << '\n';
      continue;
    }

    for (int i = 0; i < n; i += 1) {
      if (a[i] != b[i]) {
        if (!dcnt[b[i]]) {
          ok = false;
          break;
        }
        if (--dcnt[b[i]] < 0) {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}