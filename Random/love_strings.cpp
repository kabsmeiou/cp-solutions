#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt_1 = 0, cnt_0 = 0;
    for (int i = 0; i < n; i += 1) {
      cnt_1 += (s[i] == '1');
      cnt_0 += (s[i] == '0');
    }
    if (cnt_1 != cnt_0 || n & 1) {
      cout << -1 << '\n';
      continue;
    }
    deque<char> dq(s.begin(), s.end());
    vector<int> ans;
    int tot = 0;
    while (!dq.empty()) {
      if (dq.front() == dq.back()) {
        if (dq.front() == '1') {
          ans.push_back(tot);
          dq.push_front('1');
          dq.push_front('0');
        } else {
          ans.push_back(n - tot);
          dq.push_back('0');
          dq.push_back('1');
        }
        n += 2;
      }
      tot += 1;
      dq.pop_back();
      dq.pop_front();
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i += 1) {
      cout << ans[i] << " \n"[i == ans.size() - 1];
    }
  }
}