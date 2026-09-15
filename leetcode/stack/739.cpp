#include <bits/stdc++.h>
using namespace std;

/**
 * @author breadOnLaptop
 * SUBMISSION: https://leetcode.com/problems/daily-temperatures/submissions/2142648538
 *
 * TOPICS: stack, array
 *
 * @brief
 * Find the rightmost bigger temprature distance or days.
 *
 * INTUITION: Find the rightmost nearest bigger temp start from right to left using stack.
 *
 * @performance:
 * TIME: O(n)
 * SPACE: O(n)
 */

 class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        const int N = arr.size();

        vector<int> res(N, 0), st;
        for(int i{N - 1}; i >= 0; --i) {
            while(!st.empty() && arr[st.back()] <= arr[i]) st.pop_back();

            if(!st.empty()) res[i] = st.back() - i;

            st.push_back(i);
        }

        return res;
    }
};
