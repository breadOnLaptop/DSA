#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date    4rth Oct 2026
 *
 * SUBMISSION: https://leetcode.com/problems/valid-parenthesis-string/submissions/2161900541
 *
 * @brief
 * TITLE: 678. Valid Parenthesis String
 *
 * TOPICS: Dynamic Programming, String
 *
 * INTUITION:
 * - Descision tree will be made whenever '*' is observed in the tree, these are: use it as '(' or ')' or ''
 * - For the rest of the string string characters should be followed as such
 * - Optimisation for decision manupilation is to use Dynamic Programming and save the best possible result
 *
 * COMPLEXITY:
 * Time:    O(N ^ 2)
 * Space:   O(N ^ 2)
 */

 class Solution {
    private:
    int N;
    vector<vector<int>> dp;

    char solve(
        int i, int open, int close,
        const string& s
    ) {
        if(close > open) return 0;
        if(i == N) return (open == close) ? 1 : 0;
        if(dp[i][open - close] != -1) return dp[i][open - close];

        char curr = 0;
        if(s[i] == '(') curr = solve(i + 1, open + 1, close, s);
        else if(s[i] == ')') curr = solve(i + 1, open, close + 1, s);
        else {
            curr =  solve(i + 1, open + 1, close, s) ||
                    solve(i + 1, open, close + 1, s) ||
                    solve(i + 1, open, close, s);
        }

        return dp[i][open - close] = curr;
    }

    public:
    bool checkValidString(string s) {
        N = s.size();
        dp.assign(N, vector<int>(N, -1));

        return solve(0, 0, 0, s);
    }
 };
