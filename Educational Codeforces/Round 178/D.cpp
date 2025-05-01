#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  // sieve
  const int N = 1e7 + 1;
  vector<bool> prime(N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }
  int k = (int)primes.size();
  vector<int64_t> pref_primes(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    pref_primes[i] = pref_primes[i - 1] + primes[i - 1];
  }
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int64_t> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = suf[i + 1] + a[i];
    }
    int ans = 0;
    // how many primes we can take, starting at the back to optimize gold coins
    while (ans < n && suf[ans] < pref_primes[n - ans]) ans += 1;
    cout << ans << '\n';
  }
}