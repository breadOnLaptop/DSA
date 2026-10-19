/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Subset
 * LINK:     https://marisaoj.com/problem/323
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

int N, K;
vector<int> arr;

void generateSubarray(int num) {
    if(arr.size() == K) {
        for(int i = 0; i < K; i++) {
            if(i) cout << ' ';
            cout << arr[i];
        } cout << '\n';

        return;
    }
    if(num == N + 1) return;

    arr.push_back(num);
    generateSubarray(num + 1);
    arr.pop_back();

    generateSubarray(num + 1);
}

int main() {
    FASTIO

    cin >> N >> K;

    generateSubarray(1);

    return 0;
}
