#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        /*
            @author breadOnLaptop
            BEST SUBMISSION: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/submissions/2125736158

            @brief
            TITLE: 2091. Removing Minimum and Maximum From Array

            INTUITION:
            The main idea is to identify the cases where the minimum and maximum can be located in the array.

            Case distributions are as follows:
            - CASE 1: If both target values are majorly in left side
            - CASE 2: If both target values are majorly in right side
            - CASE 3: Target values from left and right

            COMPLEXITY:
            Time:   O(N)
            Space:  O(1)
        */
        const int N = nums.size();
        int mn_idx, mx_idx;
        int mn_element{INT_MAX}, mx_element{INT_MIN};
        for(int i{}; i < N; i++) {
            if(mn_element > nums[i]) {
                mn_element = nums[i];
                mn_idx = i;
            }
            if(mx_element < nums[i]) {
                mx_element = nums[i];
                mx_idx = i;
            }
        }

        int case_1, case_2, case_3;
        case_1 = max(mn_idx + 1, mx_idx + 1);
        case_2 = max(N - mn_idx, N - mx_idx);
        case_3 = min(N - mn_idx + mx_idx + 1, N - mx_idx + mn_idx + 1);

        return min({case_1, case_2, case_3});
    }
};
