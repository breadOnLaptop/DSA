/**
 * @author  breadOnLaptop
 * @date    16th Sep 2026
 *
 * SUBMISSION: https://cses.fi/paste/d59102778b2bb6d511e5186/
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO  ios::sync_with_stdio(false); \
                cin.tie(nullptr);

int main() {
    FASTIO

    int N;
    int a, b;
    vector<vector<int>> adj;

    int T = 1;
    // cin >> T;
    while(T--) {
        cin >> N;
        adj.assign(N, vector<int>());
        for(int i{}; i < N - 1; i++) {
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int global_diameter = 0;
        auto solve_dfs = [&global_diameter, &adj](auto&& self, int u, int p) -> int {
            int max1{}, max2{};
            for(int v : adj[u]) {
                if(v == p) continue;
                int child_len = 1 + self(self, v, u);

                if(child_len > max1) {
                    max2 = max1;
                    max1 = child_len;
                } else if(child_len > max2) max2 = child_len;
            }

            global_diameter = max(global_diameter, max1 + max2);

            return max1;
        };

        solve_dfs(solve_dfs, 0, -1);

        cout << global_diameter << '\n';
    }

    return 0;
}
