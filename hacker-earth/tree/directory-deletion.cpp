/**
 * @author  breadOnLaptop
 * @date    30th Sep 2026
 *
 * @brief
 * TITLE: Directory Deletion
 *
 * TOPICS: Binary Tree, Data structures, Depth First Search, Easy (wait what really!!), Trees
 *
 * SUBMISSION: https://www.hackerearth.com/submission/132031252
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

int dfs(
    int u,
    const vector<vector<int>>& adj, const vector<char>& to_delete
) {
    if(to_delete[u] == 1) return 1;

    int cnt = 0;
    for(const int& v : adj[u]) {
        cnt += dfs(v, adj, to_delete);
    }

    return cnt;
}

int main() {
    FASTIO

    int N, M;
    int LIMIT;
    vector<int> arr;
    vector<char> to_delete;
    vector<vector<int>> adj;

    cin >> N;
    arr.resize(N), to_delete.resize(N);
    for(int& i : arr) {
        cin >> i;

        if(i == -1) continue;
        --i;
        LIMIT = max(LIMIT, i);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int input; cin >> input;
        --input;
        to_delete[input] = 1;
    }

    adj.resize(LIMIT + 1);
    for(int i = 0; i < N; i++) {
        if(arr[i] == -1) continue;

        adj[arr[i]].push_back(i);
    }

    cout << dfs(0, adj, to_delete) << '\n';

    return 0;
}
