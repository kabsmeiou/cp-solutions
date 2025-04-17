#include <bits/stdc++.h>
#define int long long
using namespace std;
using namespace std::chrono;
using namespace std;
int MOD = 998244353;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 5000;
  int cnt = 0;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < n; i += 1) {
    for (int j = i; j < n; j += 1) {
      cnt += 1;
      cnt -= 1;
      cnt %= 2;
      cnt += 1;
      if (cnt % 2 == 0) {
        cnt = 2;
      }
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Time taken: " << duration.count() << " ms\n";
}
