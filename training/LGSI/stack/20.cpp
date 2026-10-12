#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date 2026-10-12
 *
 * TITLE: 20. Valid Parentheses
 * TOPIC: Stack
 */

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(char& i : s) {
            if(i == '(' || i == '{' || i == '[') st.push_back(i);
            else {
                if(i == ')') {
                    if(!st.empty() && st.back() == '(') st.pop_back();
                    else return false;
                } else if(i == ')') {
                    if(!st.empty() && st.back() == '{') st.pop_back();
                    else return false;
                } else {
                    if(!st.empty() && st.back() == '[') st.pop_back();
                    else return false;
                }
            }
        }

        return st.empty();
    }
};
