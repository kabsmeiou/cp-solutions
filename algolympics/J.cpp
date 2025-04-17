#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 998244353;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto fib = [&](int n) {
    int a = 0, b = 1;
    for (int i = 2; i <= n; i += 1) {
      int temp = b % MOD;
      b = (a % MOD + b % MOD) % MOD;
      a = temp % MOD;
    }
    return b;
  };
  string s;
  int n;
  cin >> s >> n;
  cout << (n >= 3 ? fib(n + 3) - 1 : 1 << n) << '\n';
}
