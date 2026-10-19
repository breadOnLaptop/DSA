/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: MarisaOJ
 * TITLE: 397. Integer equation
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    int a, b; cin >> a >> b;

    if(b == 0) {
        cout << "INFINITE SOLUTIONS\n";
    } else if(a == 0 || b % a != 0) {
        cout << "NO SOLUTION\n";
    } else cout << -1 * b / a << '\n';

    return 0;
 }
