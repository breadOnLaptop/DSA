/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Subset Sum
 * LINK:     https://marisaoj.com/problem/346
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

char flag = 0;

void findSubsetSum(
    int i, ll sum,
    const vector<ll>& arr,
    const int& N
) {
    if(flag == 1) return;
    if(i == N) {
        if(sum == 0LL) {
            cout << "YES\n";
            flag = 1;
        }
        return;
    }

    if(sum >= arr[i]) {
        findSubsetSum(i + 1, sum - arr[i], arr, N);
    }

    findSubsetSum(i + 1, sum, arr, N);
}

int main() {
    FASTIO

    int N;
    ll K;
    vector<ll> arr;

    cin >> N >> K;
    arr.resize(N);
    for(ll& i : arr) cin >> i;

    findSubsetSum(0, K, arr, N);

    if(flag == 0) cout << "NO\n";

    return 0;
 }
