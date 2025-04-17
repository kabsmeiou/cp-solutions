#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, b;
  cin >> n >> b;
  vector<pair<int, int>> vp(n);
  for (int i = 0; i < n; i += 1) {
    cin >> vp[i].first >> vp[i].second;
  }
  map<pair<int, int>, int> cnt;
  for (auto ac : vp) {
    int x_C = ac.first, y_C = ac.second;
    for (auto bd : vp) {
      int x_D = bd.first, y_D = bd.second;
      int numerator = y_C * y_D * b;
      int denominator = y_C * (b - x_D) + y_D * x_C;
      int gcd = __gcd(numerator, denominator);
      numerator /= gcd;
      denominator /= gcd;
      cnt[{numerator, denominator}]++;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    int gcd = __gcd(s, t);
    s /= gcd;
    t /= gcd;
    int ans = cnt[{s, t}];
    int g = __gcd(ans, n * n);
    cout << ans / g << "/" << n * n / g << "\n";
  }
  return 0;
}