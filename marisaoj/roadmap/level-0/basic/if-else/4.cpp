/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: MarisaOJ
 * TITLE: Complex multiplication
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    ll a, b, c; cin >> a >> b >> c;
    cout << a * b % c << '\n';

    return 0;
 }
