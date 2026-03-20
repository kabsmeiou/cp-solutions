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
        vector<int64_t> a(n);
        for (auto &c : a) cin >> c;
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (int i = 1; i < n; i += 2) {
            ans = max(a[i] - a[i - 1], ans);
        }
        cout << ans << '\n';
    }
}