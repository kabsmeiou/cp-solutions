#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> cnt(2*1e5 + 1, 0);
        for (int i = 0; i < n; i += 1) {
            cnt[a[i]] += 1;
        }
        int ans = 0;
        for (int i = 0; i < k; i += 1) {
            ans += (cnt[i] == 0 ? 1 : 0);
        }
        cout << ans + max(0, cnt[k] - ans) << '\n';
    }
}