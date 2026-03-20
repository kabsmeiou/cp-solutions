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
        string s;
        cin >> s;
        int switches = 0;
        int total_a = (s[0] == 'a'), total_b = (s[0] == 'b');
        for (int i = 1; i < n; i += 1) {
            if (s[i] != s[i - 1]) {
                switches += 1;
            }
            total_a += (s[i] == 'a');
            total_b += (s[i] == 'b');
        }
        if (switches <= 2) {
            cout << 0 << '\n';
            continue;
        }
        
        // left
        int l = 1;
        while (l < n && s[l] == s[0]) l += 1;
        int64_t left = 0, x = 0;
        for (int i = l; i < n; i += 1) {
            if (s[i] != s[0]) x += 1;
            else left += x;
        }
        // right
        int r = n - 2;
        while (r >= 0 && s[r] == s[n - 1]) r -= 1;
        int64_t right = 0, y = 0;
        for (int i = r; i >= 0; i -= 1) {
            if (s[i] != s[n - 1]) y += 1;
            else right += y;
        }
        
        int64_t middle = 0;

        // case where we center b (we put a aside)
        int64_t mid_a = 0;
        x = 0;
        for (int i = 0; i < n; i += 1) {
            if (s[i] == 'b') x += 1;
            else {
                mid_a += min(total_b - x, x);
            }
        }
        // case where we center a (we put b aside)
        int64_t mid_b = 0;
        x = 0;
        for (int i = 0; i < n; i += 1) {
            if (s[i] == 'a') x += 1;
            else {
                mid_b += min(total_a - x, x);
            }
        }
        // cout << mid_a << ' ' << mid_b << '\n';
        middle = min(mid_a, mid_b);
        cout << min({right, left, middle}) << '\n';
    }
}