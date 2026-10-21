/**
 * @author  breadOnLaptop
 * @date 2026-10-21
 *
 * PLATFORM: MarisaOJ
 * TITLE: 419. Segment
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    int a, b, c, d; cin >> a >> b >> c >> d;
    if((a <= c && c <= b || a <= d && d <= b) || (c <= a && a <= d || c <= b && b <= d)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
 }
