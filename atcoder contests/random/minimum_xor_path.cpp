#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  map<pair<int, int>, int> wt;
  for (int i = 0; i < m; i += 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    wt[{u, v}] = w;
    wt[{v, u}] = w;
  }
  // for (auto c : wt) {
  //   cout << c.first.first << ' ' << c.first.second << ' ' << c.second << '\n';
  // }
  int ans = (1LL << 61);
  function<void(int, vector<bool>&, int)> dfs = [&](int x, vector<bool> &vis, int tot) {
    if (x == n - 1) {
      ans = min(ans, tot);
      return;
    }
    vis[x] = true;
    for (auto ux : g[x]) {
      if (vis[ux]) continue;
      dfs(ux, vis, tot ^ wt[{x, ux}]);
    }
    vis[x] = false;
  };
  vector<bool> vis(n, 0); 
  dfs(0, vis, 0);
  cout << ans << '\n';
}