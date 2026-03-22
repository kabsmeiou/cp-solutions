#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<int> a(2 * n);
        for (auto &c : a) std::cin >> c;
        std::vector<int64_t> diff(n - 1);
        int64_t oddpairs = 0;
        for (int i = 0; i < n - 1; i += 1) {
            int idx = 2 * (i + 1);
            diff[i] = a[idx] - a[idx - 1];
            oddpairs += diff[i];
        }
        std::vector<int64_t> ediff(n);
        int64_t evenpairs = 0;
        for (int i = 0; i < n; i += 1) {
            int idx = 2 * i + 1;
            ediff[i] = a[idx] - a[idx - 1];
            evenpairs += ediff[i];
        }
        std::cout << evenpairs << ' ';
        int dstart = 0, dend = n - 2;
        int start = 0, end = n - 1;
        int left = 0, right = 2 * n - 1;
        int64_t ans = a[right] - a[left];
        for (int i = 1; i < n; i += 1) {
            if (i % 2 == 0) {
                oddpairs -= (diff[dstart] + diff[dend]);
                dstart += 1, dend -= 1;
                std::cout << ans + evenpairs << ' ';
            } else {
                evenpairs -= (ediff[start] + ediff[end]);
                start += 1, end -= 1;
                std::cout << ans + oddpairs << ' ';
            }
            left += 1, right -= 1;
            ans += (a[right] - a[left]);
        }

        std::cout << '\n';
    }
}