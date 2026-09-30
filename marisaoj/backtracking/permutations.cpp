/**
 * @author  breadOnLaptop
 * @date    30th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Permutations
 * LINK:     https://marisaoj.com/problem/546
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

int N, K;
vector<int> arr;
vector<char> visited;

void generatePermutations() {
    if((int)arr.size() == K) {
        for(int i = 0; i < K; i++) {
            if(i) cout << ' ';
            cout << arr[i];
        } cout << '\n';

        return;
    }

    for(int j = 1; j <= N; j++) {
        if(visited[j - 1] == 1) continue;

        visited[j - 1] = 1;
        arr.push_back(j);
        generatePermutations();
        arr.pop_back();
        visited[j - 1] = 0;
    }
}

int main() {
    FASTIO

    cin >> N >> K;
    visited.assign(N, 0);

    generatePermutations();

    return 0;
 }
