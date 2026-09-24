#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date    24rth Sep 2026
 *
 * SUBMISSION: https://leetcode.com/problems/island-perimeter/submissions/2152307769
 *
 * @brief
 * Stupid solution
 */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        struct COORDINATE {
            int row, col;
        };

        const int N = grid.size(), M = grid[0].size();
        const COORDINATE DIRECTION[4] {
            {-1, 0},
            {0, -1},
            {0, 1},
            {1, 0}
        };

        auto check_coordinate = [&N, &M](const int& i, const int& j) -> char {
            return (0 <= i && i < N) && (0 <= j && j < M);
        };

        auto get_cell_perimeter = [&N, &M, &grid, &DIRECTION, &check_coordinate](const int& i, const int& j) -> int {
            int perimeter = 0;
            for(const auto& dir : DIRECTION) {
                int ni = dir.row + i, nj = dir.col + j;
                if(!check_coordinate(ni, nj) || grid[ni][nj] == 0) ++perimeter;
            }

            return perimeter;
        };

        int perimeter = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == 0 || grid[i][j] == -1) continue;

                queue<COORDINATE> q;

                perimeter += get_cell_perimeter(i, j);

                q.emplace(i, j);
                grid[i][j] = -1;
                while(!q.empty()) {
                    const auto curr = q.front(); q.pop();

                    for(const auto& dir : DIRECTION) {
                        int ni = dir.row + curr.row, nj = dir.col + curr.col;
                        if(!check_coordinate(ni, nj) || grid[ni][nj] == 0 || grid[ni][nj] == -1) continue;

                        grid[ni][nj] = -1;

                        q.emplace(ni, nj);
                        perimeter += get_cell_perimeter(ni, nj);
                    }
                }
            }
        }

        return perimeter;
    }
};
