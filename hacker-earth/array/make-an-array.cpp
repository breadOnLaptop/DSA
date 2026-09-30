/**
 * @author  breadOnLaptop
 * @date    30th Sep 2026
 *
 * @brief
 * TITLE: Make an Array
 *
 * TOPICS: Math, Linear Search, Algorithms
 *
 * SUBMISSION: https://www.hackerearth.com/submission/132031137
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;

int main() {
    FASTIO

    int T = 1;
    int N;
    vector<int> arr;

    cin >> T;
    while(T--) {
        cin >> N;
        arr.resize(N);
        for(int& i : arr) cin >> i;

        ll sum = 0LL;
        for(const int& i : arr) sum += i;

        if(sum % (N - 1) != 0) {
            cout << -1 << '\n';
            continue;
        }

        int mx = *max_element(arr.begin(), arr.end());
        int K = sum / (N - 1);

        cout << (K >= mx ? K : -1) << '\n';
    }

    return 0;
}
