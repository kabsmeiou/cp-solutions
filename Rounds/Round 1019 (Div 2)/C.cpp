#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (auto &c : a) cin >> c;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i += 1) {
      cnt[i] = (a[i] <= k);
    }
    int ok = false;
    int early_ind = -1, found_less_l = -1, cur_less_l = 0;
    int cur_l = 0, l_cnt = 0;
    bool l_good = false, r_good = false;
    for (int i = 0; i < n; i += 1) {
      cur_l += 1;
      l_cnt += cnt[i];
      if (l_cnt >= (cur_l + 1) / 2 && !l_good) {
        early_ind = i;
        l_good = true;
        l_cnt = 0;
        cur_l = cur_l & 1 && i + 1 < n && a[i + 1] > k? -1 : 0;
      } else if (l_cnt >= (cur_l + 1) / 2 && l_good) {
        ok = true;
        break;
      }
    }
    int least_ind = -1, found_less_r = -1, cur_less_r = 0;
    int cur_r = 0, r_cnt = 0;
    for (int i = n - 1; i >= 0; i -= 1) {
      cur_r += 1;
      r_cnt += cnt[i];
      if (r_cnt >= (cur_r + 1) / 2 && !r_good) {
        least_ind = i;
        r_good = true;
        r_cnt = 0;
        cur_r = cur_r & 1 && i + 1 < n && a[i + 1] > k ? -1 : 0;
      } else if (r_cnt >= (cur_r + 1) / 2 && r_good) {
        ok = true;
        break;
      }
    }
    if ((early_ind != -1 && least_ind != -1) && (early_ind < least_ind && l_good && r_good)) {
      ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}