#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> prime(1e7, 1);
  prime[1] = prime[0] = 0;
  for (int i = 2; i * i <= 1e7; i += 1) {
    if (prime[i]) {
      prime[i] = 1;
      for (int k = i * i; k <= 1e7; k += i) {
        prime[k] = 0;
      }
    }
  }
  vector<int> pref(1e7 + 1, 0);
  for (int i = 1; i <= 1e7; i++) {
    prime[i] = prime[i - 1] + prime[i];
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n / 2; i >= 2; i -= 1) {
      ans += prime[(n / i)];
    }
    cout << ans + prime[n] << '\n';
  }
}