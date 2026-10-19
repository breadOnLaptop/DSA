/**
 * @author  breadOnLaptop
 * @date 2026-10-19
 *
 * PLATFORM: MarisaOJ
 * TITLE: Triangle
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int main() {
    FASTIO

    int A[3]; for(int i = 0; i < 3; i++) cin >> A[i];
    sort(A, A + 3);

    cout << (A[0] + A[1] > A[2] ? "YES" : "NO") << '\n';

    return 0;
 }
