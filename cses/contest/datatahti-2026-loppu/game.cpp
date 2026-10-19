/**
 * @author  breadOnLaptop
 * @date    20th Sep 2026
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    FASTIO

    int T = 1;
    int a, b;

    const string FIRST = "first", SECOND = "second";

    cin >> T;
    while(T--) {
        cin >> a >> b;
        if(a < b) swap(a, b);

        int k = a - b;
        double phi = (1.0 + sqrt(5)) / 2.0;

        long long eb = floor(phi * k);
        if(eb == b) cout << SECOND << '\n';
        else cout << FIRST << '\n';
    }

    return 0;
}
