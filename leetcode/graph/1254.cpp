#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date    22nd Sep 2026
 *
 * SUBMISSION: https://leetcode.com/problems/number-of-closed-islands/submissions/2152253500
 *
 * @brief
 * GIVEN: grid, DIRECTION for traversal
 *
 * DERIVED:
 * If any cell of an Island touches the edge then it is not a closed island
 *
 * INTUITION:
 * - Traverse each island and check if any cell from the same touches the edge, if touches mark the complete island
 *   impossible.
 * - While traversing every visited cell should be marked as WATER (avoids infinte tracing)
 *
 * PERFORMANCE:
 * - TIME:  O(NM)
 * - SPACE: O(NM)
 */

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        struct COORDINATE {
            int row, col;
        };

        const COORDINATE DIRECTION[4] {
            {-1, 0},
            {0, -1},
            {0, 1},
            {1, 0}
        };

        const int N = grid.size(), M = grid[0].size();

        auto check_coordinate = [&N, &M](const int& i, const int& j) -> char {
            return (0 <= i && i < N) && (0 <= j && j < M);
        };

        int cnt = 0;
        for(int i = 1; i < N - 1; i++) {
            for(int j = 1; j < M - 1; j++) {
                if(grid[i][j] == 1) continue;

                char POSSIBILITY = 1;
                queue<COORDINATE> q;

                q.emplace(i, j);
                grid[i][j] = 1;

                while(!q.empty()) {
                    const int ci = q.front().row;
                    const int cj = q.front().col;
                    q.pop();

                    for(const COORDINATE& dir : DIRECTION) {
                        int ni = ci + dir.row, nj = cj + dir.col;
                        if(!check_coordinate(ni, nj) || grid[ni][nj] == 1) continue;
                        if(ni == 0 || nj == 0 || ni == N - 1 || nj == M - 1) POSSIBILITY = 0;

                        grid[ni][nj] = 1;

                        q.emplace(ni, nj);
                    }
                }

                if(POSSIBILITY == 1) ++cnt;
            }
        }

        return cnt;
    }
};
