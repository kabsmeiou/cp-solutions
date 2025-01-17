#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    // simply take the first bit from the right where s1[i] != s2[i]
    string s1 = bitset<32>(x).to_string();
    string s2 = bitset<32>(y).to_string();
    int bit = 0;
    for (int i = 31; i >= 0; i--) {
      if (s1[i] != s2[i]) {
        cout << (1 << bit) << '\n';
        break;
      }
      bit += 1;
    }
  }
}