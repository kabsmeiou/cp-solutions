#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i += 1) {
            if (a[i] == 0) {
                ans += 1;
            }
            if (a[i] == -1) cnt += 1;
        }
        cout << ans + (cnt & 1 ? 2 : 0) << '\n';
    }
}