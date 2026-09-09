#include <bits/stdc++.h>
using namespace std;

/*
    @author breadOnLaptop
    TITLE: 743. Network Delay Time
    BEST SUBMISSION: https://leetcode.com/problems/network-delay-time/submissions/2136510724

    @topics BFS, Graph Theory, Shortest Path, Dijkstra's Algorithm

    @brief
    GIVEN:
        - Directed graph with edge weight
        - starting node from which u need to find the shortes possible connection to all nodes
        - number of nodes in the graphs

    INTUITION:
        - Simple BFS method with Bellmanford's Algorithm is required
        - Since each nodes needs to be visited we need to maintain each nodes minimum shortest path

    DERIVATION:
        - Distance based BFS with nodes = {current_node, current_time_travelled_till_now};
        - Shortest Distance maintainence with array of size = <number of nodes>;
*/

class Solution {
public:
    int networkDelayTime(const vector<vector<int>>& times, int n, int k) {
        using NODE = pair<int, int>;
        vector<vector<NODE>> adj(n);
        for(const auto& vec : times) adj[vec[0] - 1].emplace_back(NODE{vec[1] - 1, vec[2]});

        queue<NODE> q;
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        q.emplace(NODE{k - 1, 0});
        while(!q.empty()) {
            const auto [u, t] = q.front(); q.pop();

            for(const auto& [v, vt] : adj[u]) {
                int nt = vt + t;

                if(dist[v] > nt) {
                    dist[v] = nt;
                    q.emplace(NODE{v, nt});
                }
            }
        }

        int res = *max_element(dist.begin(), dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
