#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  int test_case = 1;
  while (T--) {
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<int> pre_pulbos(n + 1, 0), pre_rex(n + 1, 0);
    pre_rex[0] = h;
    for (int i = 1; i <= n; i += 1) {
      pre_pulbos[i] = pre_pulbos[i - 1] + a[i - 1];
      pre_rex[i] = pre_rex[i - 1] + b[i - 1];
    }
    int ok = false;
    int min_health = 1e9;
    for (int i = 1; i <= n; i += 1) {
      if (pre_pulbos[i] >= pre_rex[i - 1]) {
        ok = true;
        break;
      }
      min_health = min(min_health, pre_rex[i - 1] - pre_pulbos[i]);
    }
    cout << "Case #" << test_case++ << ": ";
    if (ok) {
      cout << 1 << '\n';
      continue;
    }
    int hp_left = (pre_rex[n] - pre_pulbos[n]);
    if (hp_left >= h) {
      cout << -1 << '\n';
      continue;
    }
    int hp_reduced = h - hp_left;
    cout << (min_health + hp_reduced - 1) / hp_reduced + 1 << '\n';
  }
}