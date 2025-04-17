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
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int x = *max_element(a.begin(), a.end());
    int y = *min_element(a.begin(), a.end());
    cout << ((x - y == 0) ? y : x - y) << '\n';
  }
}