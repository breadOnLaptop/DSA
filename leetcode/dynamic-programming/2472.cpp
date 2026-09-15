#include <bits/stdc++.h>
using namespace std;

/*
    @author breadOnLaptop
    SUBMISSION: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/submissions/2142528274

    @topics string, dynamic programming, 2 pointer

    @breif
    INTUITION:
    - from left to right we can find the possible number of non-overlapping palindromes with 2 pointer method
    - 1D dp is enough since we can find the best possible solution from each starting index from left to right
    - Includes the same take and not-take idea with proper checking [PALINDROMIC CHECK] of possible values we can get for the same index
*/

class Solution {
public:
    int maxPalindromes(string s, int K) {

        auto check_palindrome = [&s](int i, int j) -> bool {
            while(i < j) {
                if(s[i] != s[j]) return false;
                i++, j--;
            }

            return true;
        };

        const int N = s.size();
        vector<int> dp(N, -1);
        auto solve_top_down = [&N, &K, &s, &dp, &check_palindrome](auto&& self, int i) mutable -> int {
            if(i == N) return 0;
            if(dp[i] != -1) return dp[i];

            int curr_res = self(self, i + 1); // [NOT-TAKE]
            for(int j{i + K - 1}; j < min(N, i + K + 1); ++j) {
                if(!check_palindrome(i, j)) continue;
                curr_res = max(curr_res, 1 + self(self, j + 1)); // [TAKE]
            }

            return dp[i] = curr_res;
        };

        return solve_top_down(solve_top_down, 0);
    }
};
