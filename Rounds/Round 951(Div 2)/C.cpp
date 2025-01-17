#include <bits/stdc++.h>
#define int long long
using namespace std;

int lcm(int a, int b) {
  return a * b / __gcd(a, b);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int lc = 1;
    for (int i = 0; i < n; i += 1) {
      lc = lcm(lc, a[i]);
    }
    int total = 0;
    for (int i = 0; i < n; i += 1) {
      total += lc / a[i];
    }
    if (total >= lc) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i += 1) {
      cout << lc / a[i] << " \n"[i == n - 1];
    }
  }
}