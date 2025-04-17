#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  int test_case = 1;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = n - 1; i < j; i += 1, j -= 1) {
      ans += abs(a[i] - a[j]);
    }
    cout << "Case #" << test_case++ << ": " << ans << '\n';
  }
}