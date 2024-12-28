#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int k = n + m + 1;
    vector<int> a(k);
    vector<int> b(k);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    int x = 0, y = 0;
    int forced = -1;
    int current_sum = 0;
    vector<int> job_type(k);
    for (int i = 0; i < k - 1; i += 1) {
      if (a[i] > b[i]) {
        if (x == n) {
          forced = i;
          break;
        }
        x += 1;
        current_sum += a[i];
        job_type[i] = 0;
      } else {
        if (y == m) {
          forced = i;
          break;
        }
        y += 1;
        current_sum += b[i];
        job_type[i] = 1;
      }
    }
    bool forced_hire = a[forced] > b[forced]; // false(0) = programmer, true(1) = tester
    if (forced != -1) {
      for (int i = forced; i < k - 1; i += 1) {
        current_sum += (forced_hire ? b[i] : a[i]);
        //cout << a[i] << ' ' << b[i] << '\n';
      }
    }
    //cout << "forced: " << forced << '\n';
    vector<int> ans(k);
    for (int i = 0; i < k; i += 1) {
      int subtract = job_type[i] ? b[i] : a[i];
      if (i < forced && job_type[i] == job_type[forced] && forced != -1) {
        ans[i] = current_sum - subtract + (job_type[forced] ? a[forced] : b[forced]) + (job_type[forced] ? b[forced] : a[forced]);
      } else {
        ans[i] = current_sum - subtract + (job_type[i] ? a[i] : b[i]);
      }
    }
    for (int i = 0; i < k; i += 1) {
      cout << ans[i] << " \n"[i == k - 1];
    }
  }
}