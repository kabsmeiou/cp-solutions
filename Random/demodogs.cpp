#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    // zigzag
    int ans = (n * (n + 1)) % MOD;
    ans %= MOD;
    ans *= (4 * n - 1) % MOD;
    ans %= MOD;
    ans *= 337 % MOD;
    ans %= MOD;
    cout << ans << '\n';
  }
}