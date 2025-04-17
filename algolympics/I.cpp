#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 998244353;
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
    // pair number of {occurences, divisors}
    // every bit that is 0 is divisible? maybe n lg n solution
    map<int, int> occ;
    map<int, int> divisors;
    int ans_max = n, ans_min = n;
    for (auto &c : a) cin >> c, occ[c] += 1;
    sort(a.begin(), a.end());
    map<int, int> vis;
    for (int i = 0; i < n; i += 1) {
      if (vis[a[i]]) continue;
      for (int j = i; j < n; j += 1) {
        if (i == j) continue;
        divisors[a[i]] += (a[j] % a[i] == 0); 
      }
      vis[a[i]] = 1;
    }
    // for (auto &c : divisors) {
    //   cout << c.first << ' ';
    //   cout << c.second << '\n';
    //   // c.second = c.second / occ[c.first];
    // }
    // cout << '\n';
    for (int i = 0; i < n; i += 1) {
      int k = divisors[a[i]], ret = 1, base = 2;
      while (k > 0) {
        if (k & 1) ret = ret * base % MOD;
        base = (base * base) % MOD;
        k >>= 1;
      }
      ans_min += ret % MOD - 1, ans_min %= MOD;
      divisors[a[i]] -= 1;
    }
    for (auto c : occ) {
      int k = c.second, ret = 1, base = 2;
      while (k > 0) {
        if (k & 1) ret = ret * base % MOD;
        base = (base * base) % MOD;
        k >>= 1;
      }
      ans_max += ret % MOD - c.second - 1;
      ans_max %= MOD;
    }
    cout << ans_max % MOD << ' ' << ans_min % MOD << '\n';
  }
}