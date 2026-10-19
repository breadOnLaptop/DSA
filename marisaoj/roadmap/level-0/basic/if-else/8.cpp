/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: MarisaOJ
 * TITLE: 420. Age
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    cout << (tie(c, b, a) < tie(z, y, x) ? 1 : 2) << '\n';

    return 0;
 }
