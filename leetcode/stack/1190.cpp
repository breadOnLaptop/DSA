#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * SUBMISSION: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/submissions/2155184723
 *
 * @brief
 * GIVEN: string consisting lowercase alphabets and parenthesis
 *
 * INTUITION: based on the parenthesis get substring range into the stack and later reverse while closing
 *
 * PERFORMANCE:
 * TIME:    O(N ^ 2)
 * SPACE:   O(N)
 */

 class Solution {
public:
    string reverseParentheses(string s) {
        const int N = s.size();
        vector<int> st;

        int i = 0;
        while(i < N) {
            if(s[i] == '(') {
                st.push_back(i);
            } else if(s[i] == ')') {
                reverse(s.begin() + st.back(), s.begin() + i + 1);
                st.pop_back();
            }
            ++i;
        }

        string res = "";
        for(const char& c : s) {
            if(c == '(' || c == ')') continue;

            res += c;
        }

        return res;
    }
};
