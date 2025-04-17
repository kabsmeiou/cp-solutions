#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> s(n);
    map<char, int> cnt_1, cnt_2;
    map<char, map<char, int>> cnt_3;
    for (auto &str : s) {
      cin >> str;
      cnt_1[str[0]]++;
      cnt_2[str[1]]++;
      cnt_3[str[0]][str[1]]++;
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (cnt_1[s[i][0]] - cnt_3[s[i][0]][s[i][1]]);
      ans += (cnt_2[s[i][1]] - cnt_3[s[i][0]][s[i][1]]);
      cnt_1[s[i][0]]--, cnt_2[s[i][1]]--, cnt_3[s[i][0]][s[i][1]]--;
    }
    cout << ans << '\n';
  }
}