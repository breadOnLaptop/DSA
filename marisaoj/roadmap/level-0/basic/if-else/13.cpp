/**
 * @author  breadOnLaptop
 * @date 2026-10-21
 *
 * PLATFORM: MarisaOJ
 * TITLE: 7. Rectangle
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    int a, b, c; cin >> a >> b >> c;
    if(a != b && a != c) cout << a << '\n';
    else if(a != b) cout << b << '\n';
    else cout << c << '\n';

    return 0;
 }
