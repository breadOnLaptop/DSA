#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date    16th Sep 2026
 *
 * SUBMISSION: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/submissions/2143972406
 *
 * TOPIC: dynamic programming, math, combinatorics
 */

using ll = long long;

constexpr int MOD = 1e9 + 7;

enum class STATUS {
    DRAWING,
    NOT_DRAWING
};


class Solution {
public:
    int numberOfSets(int N, int K) {
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K + 1, vector<int>(2, -1)));
        auto solve_top_down = [&N, &K, &dp](auto&& self, int i, int j, STATUS status) {
            if(j == K) return 1;
            if(i == N) return 0;

            int s = STATUS::NOT_DRAWING == status;
            if(dp[i][j][s] != -1) return dp[i][j][s];

            ll ways = 0;

            if(status == STATUS::NOT_DRAWING) {
                ways = (ways + self(self, i + 1, j, STATUS::NOT_DRAWING)) % MOD;
                ways = (ways + self(self, i + 1, j, STATUS::DRAWING)) % MOD;
            } else {
                ways = (ways + self(self, i + 1, j, STATUS::DRAWING)) % MOD;
                ways = (ways + self(self, i, j + 1, STATUS::NOT_DRAWING)) % MOD;
            }

            return dp[i][j][s] = ways;
        };

        return solve_top_down(solve_top_down, 0, 0, STATUS::NOT_DRAWING);
    }
};
