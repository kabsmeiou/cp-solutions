#include <bits/stdc++.h>
using namespace std;

// struct bt {
//   char dir;
//   bt* left;
//   bt* right;

//   bt(char d) : dir(d), left(nullptr), right(nullptr) {}
// };

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // bt* cur = new bt(s[0]);
    vector<vector<int>> bintree(n, vector<int>(2));
    vector<bool> is_leaf(n, false);
    for (int i = 0; i < n; i += 1) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      bintree[i][0] = l;
      bintree[i][1] = r;
      is_leaf[i] = (l == -1 && r == -1);                                                             
    }
    int ans = 3 * 1e5;
    function<void(int, int)> dfs = [&](int u, int cost) {
      if (is_leaf[u]) {
        ans = min(ans, cost);
        return;
      }
      int l = bintree[u][0], r = bintree[u][1];
      if (l != -1) {
        dfs(l, cost + (s[u] == 'L' ? 0 : 1));
      }
      if (r != -1) {
        dfs(r, cost + (s[u] == 'R' ? 0 : 1));
      }
    };
    dfs(0, 0);
    cout << ans << '\n';
  }
}