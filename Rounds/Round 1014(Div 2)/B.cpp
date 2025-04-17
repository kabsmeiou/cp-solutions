#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int s_cnt_odd = 0, s_cnt_even = 0;
    int b_cnt_odd = 0, b_cnt_even = 0;
    for (int i = 1; i <= n; i += 1) {
      if (a[i - 1] == '1') {
        s_cnt_odd += (i & 1);
        s_cnt_even += (i % 2 == 0);
      }
      if (b[i - 1] == '0') {
        b_cnt_odd += (i & 1);
        b_cnt_even += (i % 2 == 0);
      }
    }
    int ok_1 = (b_cnt_even >= s_cnt_odd && b_cnt_odd >= s_cnt_even);
    // cout << b_cnt_even << ' ' << b_cnt_odd << '\n';
    // cout << s_cnt_even << ' ' << s_cnt_odd << '\n';
    cout << (ok_1 ?  "YES" : "NO") << '\n';
  }
}