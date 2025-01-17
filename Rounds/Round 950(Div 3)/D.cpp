
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int current = -1, ind = -1;
    for (int i = 0; i < n - 1; i += 1) {
      int have = __gcd(a[i], a[i + 1]);
      //cout << have << ' ';
      if (have < current) {
        ind = i;
        break;
      }
      current = have;
    }
    //cout << '\n';
    int shifter[3]{-1, 0, 1};
    bool good = false;
    
    for (int k = 0; k < 3; k += 1) {
      int to_skip = ind + shifter[k];
      //cout << to_skip << '\n';
      vector<int> x;
      for (int i = 0; i < n; i += 1) {
        if (i == to_skip) {
          continue;
        }
        x.push_back(a[i]);
      }
      bool ok = true;
      int cur = -1;
      for (int i = 0; i < x.size() - 1; i += 1) {
        int have = __gcd(x[i], x[i + 1]);
        if (have < cur) {
          ok = false;
          break;
        }
       cur = have;
      }
      good |= ok;
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}
