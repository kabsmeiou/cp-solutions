#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, f;
  cin >> n >> m >> f;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i += 1) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> ans(n, 1e5);
  vector<int> fex(f);
  for (int i = 0; i < f; i += 1) {
    int x;
    cin >> x;
    x -= 1;
    fex[i] = x;
    ans[x] = 0;
  }
  function<void(int)> bfs = [&](int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto w : g[v]) {
        if (ans[w] <= ans[v] + 1) continue;
        ans[w] = ans[v] + 1;
        q.push(w);
      }
    }
  };
  for (int i = 0; i < f; i += 1) {
    bfs(fex[i]);
  }
  int ret = 0;
  for (int i = 0; i < n; i += 1) {
    ret = max(ret, ans[i]);
  }
  cout << ret << '\n';
}