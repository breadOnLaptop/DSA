/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: MarisaOJ
 * TITLE: Mushroom Classification
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    float a; cin >> a;
    if(a >= 9.0) cout << "VERY TOXIC\n";
    else if(5.0 <= a && a < 9.0) cout << "TOXIC\n";
    else cout << "SAFE\n";

    return 0;
 }
