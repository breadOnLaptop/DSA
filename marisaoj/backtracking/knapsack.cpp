/**
 * @author  breadOnLaptop
 * @date    3rd Oct 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Knapsack
 * LINK:     https://marisaoj.com/problem/54
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int N, S;
vector<int> w, v;

ll knapsack(int i, ll curr_w) {
    if(i == N) return 0;

    ll t = 0;
    if(curr_w + w[i] <= S) t = v[i] + knapsack(i + 1, curr_w + w[i]);

    ll nt = knapsack(i + 1, curr_w);

    return max(t, nt);
}

int main() {
    FASTIO

    cin >> N >> S;
    w.resize(N); v.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    cout << knapsack(0, 0) << '\n';

    return 0;
 }
