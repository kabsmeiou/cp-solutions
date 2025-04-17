#include <bits/stdc++.h>
#define int long long
using namespace std;

class substringHashing {
  public:
    string s;
    int p, m1, m2, n;
    vector<int> pref_hash_left, pref_hash_right;
    vector<int> p_pow_left, p_pow_right;
    substringHashing(string &s_) {
      p = 31;
      s = s_;
      n = s.size();
      m1 = 1000005737;
      m2 = 1000000181;
      initializePower();
      initializePrefixHash(pref_hash_left, m1);
      initializePrefixHash(pref_hash_right, m2);
    }

    void initializePower() {
      p_pow_left = vector<int>(n + 1, 1);
      p_pow_right = vector<int>(n + 1, 1);
      for (int i = 1; i <= n; i += 1) {
        p_pow_left[i] = (p_pow_left[i - 1] * p) % m1;
        p_pow_right[i] = (p_pow_right[i - 1] * p) % m2;
      }
    }

    void initializePrefixHash(vector<int> &pref_hash, int m) {
      pref_hash = vector<int>(n, 0);
      int hash_val = 0;
      for (int i = 0; i < n; i += 1) {
        hash_val = (hash_val * p + (s[i] - '0' + 1)) % m;
        pref_hash[i] = hash_val;
      }
    }

    int computeHash(int l, int r, vector<int> &pref_hash, int m, vector<int> &p_pow) {
      int res = pref_hash[r];
      if(l != 0) res -= ((pref_hash[l-1] % m)*(p_pow[r - l + 1] % m)) % m;
      return (res % m + m) % m;
    }    

    pair<int, int> getHash(int l, int r) {
      return {computeHash(l, r, pref_hash_left, m1, p_pow_left), computeHash(l, r, pref_hash_right, m2, p_pow_right)};
    }
};


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string r = s;
    reverse(r.begin(), r.end());
    substringHashing sh(s);
    substringHashing rh(r);
    // generate 2 possible answers on k
    string ans_1 = "", ans_2 = "";
    for (int i = 0; i < n; i += 1) {
      if (i / k % 2) {
        ans_1 += '1';
        ans_2 += '0';
      } else {
        ans_1 += '0';
        ans_2 += '1';
      }
    }
    substringHashing ans1_hash(ans_1);
    substringHashing ans2_hash(ans_2);
    if (sh.getHash(0, n - 1) == ans1_hash.getHash(0, n - 1) || sh.getHash(0, n - 1) == ans2_hash.getHash(0, n - 1)) {
      cout << n << '\n';
      continue;
    }
    int ret = -1;
    for (int i = 1; i < n; i += 1) {
      pair<int, int> left_hash = sh.getHash(i, n - 1);
      pair<int, int> right_hash = rh.getHash(n - i, n - 1);
      pair<int, int> ans1_left = ans1_hash.getHash(0, n - 1 - i), ans1_right = ans1_hash.getHash(n - i, n - 1);
      if (ans1_left == left_hash && ans1_right == right_hash) {
        ret = i;
        break;
      }
      pair<int, int> ans2_left = ans2_hash.getHash(0, n - 1 - i), ans2_right = ans2_hash.getHash(n - i, n - 1);
      if (ans2_left == left_hash && ans2_right == right_hash) {
        ret = i;
        break;
      }
    }
    cout << ret << '\n';
  }
}