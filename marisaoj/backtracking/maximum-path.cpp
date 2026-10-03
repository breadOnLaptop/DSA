/**
 * @author  breadOnLaptop
 * @date
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Maximum Path
 * LINK:     https://marisaoj.com/problem/55
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int grid[4][4];

constexpr int DIRECTION[2][2] = {{1, 0}, {0, 1}};

ll solve(int i, int j, ll curr_sum) {

    if(i == 3 && j == 3) return curr_sum;

    ll curr = 0;
    for(int d = 0; d < 2; d++) {
        int ni = i + DIRECTION[d][0], nj = j + DIRECTION[d][1];

        if(0 <= ni && ni < 4 && 0 <= nj && nj < 4) {
            curr = max(solve(ni, nj, curr_sum + grid[ni][nj]), curr);
        }
    }

    return curr;
}

int main() {
    FASTIO

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cout << solve(0, 0, grid[0][0]) << '\n';

    return 0;
 }
