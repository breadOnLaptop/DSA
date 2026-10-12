#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date 2026-10-12
 *
 * TITLE: 2696. Minimum String Length After Removing Substrings
 * TOPIC: Stack
 */

class Solution {
    public:
    int minLength(string s) {
        vector<char> st;
        for(char& c : s) {
            st.push_back(c);
            while(st.size() >= 2 && ((st[st.size() - 2] == 'A' && st[st.size() - 1] == 'B') || (st[st.size() - 2] == 'C' && st[st.size() - 1] == 'D'))) {
                st.pop_back(), st.pop_back();
            }

            // cout << "[DEBUG]: ";
            // for(const char& i : st) cout << i << ' ';
            // cout << '\n';
        }

        return st.size();
    }
};
