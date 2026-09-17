/**
 * @author  breadOnLaptop
 * @date    17th Sep 2026
 *
 * SUBMISSION: https://cses.fi/paste/e5ec15f0c895591911e800e
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO  ios::sync_with_stdio(false); \
                cin.tie(nullptr);

int main() {
    FASTIO

    int N;
    int u, v;
    int global_cnt = 0;
    vector<char> visited;
    vector<vector<int>> adj;

    auto dfs = [&N, &global_cnt, &visited, &adj](auto&& self, int u, int p) mutable -> void {
        for(const int& v : adj[u]) {
            if(v == p) continue;

            self(self, v, u);

            if(!visited[v] && !visited[u]) {
                visited[v] = visited[u] = 1;
                ++global_cnt;
            }
        }
    };

    int T = 1;
    // cin >> T;
    while(T--) {
        cin >> N;
        visited.assign(N, 0);
        adj.assign(N, vector<int>());
        for(int i{}; i < N - 1; i++) {
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(dfs, 0, -1);
        cout << global_cnt << '\n';
    }

    return 0;
}
