/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: MarisaOJ
 * TITLE: Combine rectangles
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

    if((a == c || a == d) || (b == c || b == d)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
 }
