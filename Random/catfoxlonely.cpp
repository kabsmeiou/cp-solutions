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
    int total = 0;
    for (auto &c : a) cin >> c, total |= c;
    auto check = [&](int k) -> bool {
      vector<int> bit_cnt(22, 0);
      for (int i = 0; i < k; i += 1) {
        int x = a[i];
        for (int j = 21; j >= 0; j -= 1) {
          if (x >= (1 << j)) { // if bit is activated
            x -= (1 << j);
            bit_cnt[j] += 1; // add to the bit counter
          }
        }
      }
      // get sub_total for comparison to total (equivalence)
      int sub_total = 0;
      for (int i = 0; i <= 21; i += 1) {
        if (bit_cnt[i]) {
          sub_total += (1 << i);
        }
      }
      if (sub_total != total) return false;
      // sliding window is now possible with bit_cnt
      for (int i = 1; i + k - 1 < n; i += 1) {
        int x = a[i - 1];
        for (int j = 21; j >= 0; j -= 1) {
          if (x >= (1 << j)) {
            x -= (1 << j);
            bit_cnt[j] -= 1;
            if (!bit_cnt[j]) {
              sub_total -= (1 << j);
            }
          }
        }
        int y = a[i + k - 1];
        for (int j = 21; j >= 0; j -= 1) {
          if (y >= (1 << j)) {
            y -= (1 << j);
            bit_cnt[j] += 1;
            if (bit_cnt[j] == 1) {
              sub_total += (1 << j);
            }
          }
        }
        if (sub_total != total) return false;
      }
      return true;
    };
    int l = 1, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l << '\n';
  }
}