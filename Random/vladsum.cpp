#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 200001;
int cnt[MAX];

int precompute(int x) {
  int res = 0;
  while (x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  int ans = cnt[n];
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i < MAX; i++) {
    cnt[i] = cnt[i - 1] + precompute(i);
  }
  while (T--) solve();
  return 0;
}