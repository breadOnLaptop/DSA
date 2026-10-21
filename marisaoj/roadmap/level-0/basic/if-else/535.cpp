/**
 * @author  breadOnLaptop
 * @date 2026-10-21
 *
 * PLATFORM: MarisaOJ
 * TITLE: 535. Calculator
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    double a, b;
    char c;
    cin >> a >> c >> b;

    double R;
    if(c == '*') {
        R = a * b;
    } else if(c == '+') R = a + b;
    else if(c == '-') R = a - b;
    else {
        if(b == 0.0) {
            cout << "ze\n";
            return 0;
        }
        R = a / b;
    }

    cout << fixed << setprecision(3) << R << '\n';

    return 0;
 }
