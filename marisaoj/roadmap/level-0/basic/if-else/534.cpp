/**
 * @author  breadOnLaptop
 * @date 2026-10-21
 *
 * PLATFORM: MarisaOJ
 * TITLE: 534. Circle
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    double pi = 3.14, r;
    cin >> r;
    double c = pi * r * 2, a = pi * r * r;
    cout << fixed << setprecision(3) << c << ' ' << a << '\n';

    return 0;
 }
