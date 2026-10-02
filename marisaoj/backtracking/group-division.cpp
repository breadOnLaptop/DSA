/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Group Division
 * LINK:     https://marisaoj.com/problem/545
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int N, K;
int TARGET;
vector<int> arr, res;
vector<char> visited;

char groupDivision(int cnt, int curr) {
    if(curr > TARGET) return 0;
    if(curr == TARGET) {
        if(cnt == K - 1) return 1;
        if(groupDivision(cnt + 1, 0)) return 1;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i] == 1) continue;

        visited[i] = 1;
        res[i] = cnt + 1;
        if(groupDivision(cnt, curr + arr[i]) == 1) return 1;
        visited[i] = 0;
    }

    return 0;
}

int main() {
    FASTIO

    cin >> N >> K;

    arr.resize(N), res.resize(N);
    visited.assign(N, 0);

    for(int& i : arr) {
        cin >> i;
        TARGET += i;
    }

    if(TARGET % K != 0) {
        cout << "ze\n";
        return 0;
    } TARGET /= K;

    if(groupDivision(0, 0) == 1) {
        for(int i = 0; i < N; i++) {
            if(i) cout << ' ';

            cout << res[i];
        } cout << '\n';
    }

    return 0;
 }
