#include <iostream>

signed main() {
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        char c;
        std::string s;
        std::cin >> n >> c >> s;
        bool ok = true;
        int cnt = 0;
        for (int i = 0; i < n; i += 1) {
            if (s[i] != c) {
                ok = false;
                cnt += 1;
            }
        }
        if (ok) {
            std::cout << 0 << '\n';
        } else {
            int pos = 0;
            for (int i = n / 2; i < n; i += 1) {
                if (s[i] == c) {
                    pos = i;
                    break;
                }
            }
            if (pos) {
                std::cout << 1 << '\n';
                std::cout << pos + 1 << '\n';
            } else {
                std::cout << 2 << '\n';
                std::cout << n << ' ' << n - 1 << '\n';
            }
        }
    }
}