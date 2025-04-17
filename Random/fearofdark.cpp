#include <bits/stdc++.h>
#define int double
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    int a_dist_from_start = ax * ax + ay * ay;
    int b_dist_from_start = bx * bx + by * by;
    int a_dist_from_p = abs(px - ax) * abs(px - ax) + abs(py - ay) * abs(py - ay);
    int b_dist_from_p = abs(px - bx) * abs(px - bx) + abs(py - by) * abs(py - by);
    if (a_dist_from_p <= b_dist_from_p && a_dist_from_start <= b_dist_from_start) {
      int radius = sqrt(max(a_dist_from_p, a_dist_from_start));
      cout << fixed << setprecision(12) << radius << '\n';
    } else if (b_dist_from_p <= a_dist_from_p && b_dist_from_start <= a_dist_from_start) {
      int radius = sqrt(max(b_dist_from_p, b_dist_from_start));
      cout << fixed << setprecision(12) << radius << '\n';
    } else {
      int radius = 1e9;
      int point_dist = sqrt(abs(ax - bx) * abs(ax - bx) + abs(ay - by) * abs(ay - by));
      radius = min(radius, max({point_dist / 2, sqrt(a_dist_from_p), sqrt(b_dist_from_start)}));
      radius = min(radius, max({point_dist / 2, sqrt(b_dist_from_p), sqrt(a_dist_from_start)}));
      cout << fixed << setprecision(12) << radius << '\n';
    }
  }
}