#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &c : a) cin >> c;
  vector<int> pref(n, 0);
  for (int i = 1; i < n - 1; i += 1) {
    pref[i] = pref[i - 1] + (a[i - 1] >= a[i] && a[i] >= a[i + 1]);
  }
  for (auto c : pref) cout << c << ' ';
  cout << '\n';
  for (int i = 0; i < q; i += 1) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << (l == r ? 1 : (r - l + 1) - pref[r - 1] + pref[l]) << '\n';
  }
}