#include <bits/stdc++.h>
using namespace std;

/*
    @author breadOnLaptop
    TITLE: 787. Cheapest Flights Within K Stops
    BEST SUBMISSION: https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/2136544144

    @topics BFS, Graph Theory, Shortest Path, Dijkstra's Algorithm

    @brief
    GIVEN:
        - Directed graph with edge weight
        - soruce node number
        - destination node number
        - Max limit on number of stops for a given path

    INTUITION:
        - Simple BFS method with Bellmanford's Algorithm is required with number of stops to manage
        - Since each nodes needs to be visited we need to maintain each nodes minimum shortest path which includes {current node, distance travelled, number of stops used}

    DERIVATION:
        - Distance based BFS with nodes = {current node, distance travelled, number of stops used};
        - Shortest Distance maintainence with array of size = <number of nodes>;
        - At last check the destination is reached or not, and return accordingly
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Denotes: [CURRENT_NODE, WEIGHT from PARENT to CURRENT node]
        using NODE = pair<int, int>;
        vector<vector<NODE>> adj(n);
        for(const auto& vec : flights) adj[vec[0]].emplace_back(NODE{vec[1], vec[2]});

        vector<int> dist(n, INT_MAX); dist[src] = 0;

        // Denotes: [CURRENT_NODE, WEIGHT from PARENT to CURRENT node, STOPS used till now]
        using TRAVERSAL_NODE = tuple<int, int, int>;
        queue<TRAVERSAL_NODE> q; q.emplace(TRAVERSAL_NODE{src, 0, k});
        while(!q.empty()) {
            const auto [u, d, kk] = q.front(); q.pop();

            for(const auto& [v, dd] : adj[u]) {
                int nd = dd + d;

                if(kk >= 0 && nd < dist[v]) {
                    dist[v] = nd;
                    q.emplace(TRAVERSAL_NODE{v, nd, kk - 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
