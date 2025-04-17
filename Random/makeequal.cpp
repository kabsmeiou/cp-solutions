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
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 2;
    bool ok = true;
    set<int> s;
    for (auto c : a) s.insert(c % ans);
    if (s.size() != 2) {
      ok = false;
    }
    if (ok) {
      cout << ans << '\n';
      continue;
    }
    while (s.size() != 2) {
      s.clear();
      ans *= 2;
      for (auto num : a) s.insert(num % ans);
    } 
    cout << ans << '\n';
  }
}