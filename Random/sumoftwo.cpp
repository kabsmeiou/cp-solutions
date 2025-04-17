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
    string s = to_string(n);
    string x = "" , y = "";
    bool ok = false, alternate = false;
    for (int i = 0; i < s.size(); i += 1) {
      int c = s[i] - '0';
      if (c & 1) {
        if (!alternate) {
          x += to_string(c / 2);
          y += to_string(c / 2 + 1);
        } else {
          x += to_string(c / 2 + 1);
          y += to_string(c / 2);
        }
        alternate = !alternate;
        ok = true;
      } else {
        x += to_string(c / 2);
        y += to_string(c / 2);
      }
    }
    cout << stoi(x) << ' ' << stoi(y) << '\n';
  }
}