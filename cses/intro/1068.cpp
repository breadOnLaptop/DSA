/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: cses
 * TITLE: 1068. Weird Algorithm
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    int n; cin >> n;

    while(n != 1) {
        cout << n << ' ';
        if(n % 2 == 0) n /= 2;
        else n = (n * 3) + 1;
    }

    cout << 1 << '\n';

    return 0;
 }
