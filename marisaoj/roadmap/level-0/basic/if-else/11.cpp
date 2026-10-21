/**
 * @author  breadOnLaptop
 * @date 2026-10-21
 *
 * PLATFORM: MarisaOJ
 * TITLE: Rounded division
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    float a, b;
    cin >> a >> b;
    cout << fixed << setprecision(2) << a / b << '\n';

    return 0;
 }
