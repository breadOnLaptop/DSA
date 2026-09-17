/**
 * @author  breadOnLaptop
 * @date    17th Sep 2026
 *
 * SUBMISSION: https://cses.fi/paste/bb8dbda845ab756411e7ea3
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO  ios::sync_with_stdio(false); \
                cin.tie(nullptr);

int main() {
    FASTIO

    int N, u;
    vector<int> sub;
    vector<vector<int>> adj;

    auto dfs = [&N, &sub, &adj](auto&& self, int u) -> int {
        if(u == N) return 0;

        int cnt = 0;
        for(const int& v : adj[u]) {
            cnt += 1 + self(self, v);
        }

        return sub[u] = cnt;
    };

    int T = 1;
    // cin >> T;
    while(T--) {
        cin >> N;
        adj.assign(N, vector<int>());
        for(int v{1}; v < N; v++) {
            cin >> u;
            --u;
            adj[u].push_back(v);
        }

        sub.assign(N, 0);
        dfs(dfs, 0);

        for(int i{0}; i < N; i++) {
            if(i) cout << ' ';
            cout << sub[i];
        }
        cout << '\n';
    }

    return 0;
}
