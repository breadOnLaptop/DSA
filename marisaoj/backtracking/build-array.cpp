/**
 * @author  breadOnLaptop
 * @date    4rth Oct 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Build Array
 * LINK:     https://marisaoj.com/problem/56
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int N, M, Q;
vector<int> arr;
vector<vector<int>> condition;

int solve(int i) {
    if(i == N) {
        for(int k = 0; k < Q; k++) {
            if(arr[condition[k][0]] + arr[condition[k][1]] != condition[k][2]) return 0;
        }

        return 1;
    }

    int cnt = 0;
    for(int k = 1; k <= M; k++) {
        arr[i] = k;
        cnt += solve(i + 1);
    }

    return cnt;
}

int main() {
    FASTIO

    cin >> N >> M >> Q;
    arr.assign(N, 0), condition.resize(Q);
    for(int i = 0; i < Q; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        --a, --b;

        condition[i] = {a, b, k};
    }

    cout << solve(0) << '\n';

    return 0;
 }
