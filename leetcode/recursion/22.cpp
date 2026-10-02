#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date    2nd Oct 2026
 *
 * SUBMISSION: https://leetcode.com/problems/generate-parentheses/submissions/2159972217
 *
 * @brief
 * TITLE: 22. Generate Parentheses
 *
 * TOPICS: Recursion, Backtracking
 *
 * PREREQUISITES: Recursion, Backtracking
 *
 * INTUITION:
 * - Maintain two variables (open, close) which will track the number of open and closed parentheses
 * - pushes closed parentheses only when open counts increases
 * - LIMIT of the idea generated permutation of such will always be N * 2
 *
 * COMPLEXITY:
 * Time:    O(2 ^ N)
 * Space:   O(2 ^ N)
 */

 class Solution {
    private:
    int LIMIT;
    string curr;
    vector<string> res;

    void generateParentheses(int open, int close) {
        if(open + close == LIMIT) {
            res.push_back(curr);

            return;
        }

        if(open < LIMIT / 2) {
            curr += '(';
            generateParentheses(open + 1, close);
            curr.pop_back();
        }

        if(close < open) {
            curr += ')';
            generateParentheses(open, close + 1);
            curr.pop_back();
        }
    }

    public:
    vector<string> generateParenthesis(int n) {
        LIMIT = n * 2;

        generateParentheses(0, 0);

        return res;
    }
 };
