#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            @author breadOnLaptop
            BEST SUBMISSION: https://leetcode.com/problems/rotting-oranges/submissions/2125697009

            @brief
            TITLE: 994. Rotting Oranges

            INTUITION:
            From the question we can derive, mutated oranges acts as sources and will reach it's neighbors 1 min each.
            Direction of spreading the mutation are: {TOP, BOTTOM, LEFT, RIGHT}
            Constraints:
                - Mutated orange:   2
                - Fresh Orange:     1
                - No orange:        0
            We cannot mutate at cell value 0

            DERIVATION: Use Multisource BFS stream using queue as we are spreading the mutation in level wise traversal.

            NODE: a tuple of 3 int's which will have coordinates and the time at which the fresh orange is mutated in {i, j, t/d}

            COMPLEXITY:
            Time:   O(N * M)
            Space:  O(N * M)
        */

        const int N = grid.size(), M = grid[0].size();

        using node = tuple<int, int, int>;
        int cnt{};
        queue<node> q;
        for(int i{}; i < N; i++) {
            for(int j{}; j < M; j++) {
                int& val = grid[i][j];
                if(val == 2) {
                    q.emplace(node{i, j, 0});
                } else if(val == 1) {
                    ++cnt;
                }
            }
        }

        const pair<int, int> dirs[] = {
            {0, 1}, {1, 0},
            {-1, 0}, {0, -1}
        };

        auto check_coordinates = [&N, &M](const int& i, const int& j) -> bool {
            return 0 <= i && i < N && 0 <= j && j < M;
        };

        int res{};
        while(!q.empty()) {
            const auto [i, j, d] = q.front(); q.pop();

            res = max(res, d);

            for(const auto& [di, dj] : dirs) {
                int ni = i + di, nj = j + dj, nd = d + 1;
                if(!check_coordinates(ni, nj)) continue;

                if(grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    q.emplace(node{ni, nj, nd});
                    --cnt;
                }
            }
        }
        return cnt == 0 ? res : -1;
    }
};
