#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        if (s.size() == 1) {
            cout << (s[0] == '0' ? 0 : 1) << '\n';
            continue;
        }
        string k = s + s;
        int n = (int)k.size();
        int N = (int)s.size();
        int64_t ret = 0;
        int64_t cur = 0;
        for (int i = 0; i < n; i += 1) {
            if (k[i] == '1') {
                cur += 1;
            } else {
                ret = max(cur, ret);
                cur = 0;
            }
        }
        ret = max(cur, ret);
        ret = min(ret, 1LL * N);
        if (ret == 1) {
            cout << 1 << '\n';
            continue;
        } else if (ret == N) {
            cout << N * 1LL * N << '\n';
            continue;
        }
        cout << ((ret + 1) / 2) * ((ret + 2) / 2)  << '\n';
    }
}