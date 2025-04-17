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
    cout << "Case #" << test_case++ << ": ";
    cout << (n >= 3 ? 6 : 1) << '\n';
  }
}