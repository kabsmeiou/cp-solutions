#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    map<int, int> vertices;
    for (auto &c : a) cin >> c, vertices[c] = 1;
    vertices[0] = vertices[n]; // set last vertex to true if it exists.
    int ans = x - 2;
    for (int i = 0; i < x; i++) {
      ans += (vertices[(a[i] + 2) % n] && !vertices[(a[i] + 1) % n]);
    }
    cout << min(ans, n - 2) << '\n';
  }
}