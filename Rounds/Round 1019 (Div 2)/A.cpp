#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int ans = 0;
    map<int, int> unq;
    for (int i = 0; i < n; i += 1) {
      unq[a[i]] += 1;
    }
    cout << unq.size() << '\n';
  }
}