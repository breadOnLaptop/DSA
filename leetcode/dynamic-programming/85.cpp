#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date 2026-10-12
 *
 * TITLE: 85. Maximal Rectangle
 * TOPIC: DP, Monotonic Stack
 */

class Solution {
    public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        int mx = 0;
        vector<int> st, dp(M, 0);
        for(int i = 0; i < N; i++) {
            int j;
            for(j = 0; j < M; j++) {
                dp[j] = matrix[i][j] == '0' ? 0 : dp[j] + 1;
            }

            // cout << "[DEBUG]: ";
            // for(int k = 0; k < M; k++) {
            //     if(k) cout << ' ';
            //     cout << dp[k];
            // } cout << '\n';

            j = 0;
            st.clear();
            while(j <= M) {
                int curr = j == M ? 0 : dp[j];
                while(!st.empty() && curr < dp[st.back()]) {
                    int l = dp[st.back()]; st.pop_back();
                    int b = st.empty() ? j : j - st.back() - 1;

                    mx = max(mx, l * b);
                }

                st.push_back(j);
                ++j;
            }
        }

        return mx;
    }
};
