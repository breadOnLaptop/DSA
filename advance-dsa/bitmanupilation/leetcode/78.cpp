#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date 2026-10-11
 *
 * @brief
 * TITLE: 78. Subsets
 *
 * TOPICS: Bit Manupilation
 *
 * PREREQUISITES: Bit Manupilation
 *
 * INTUITION: Based On the relation with the expansion of power set which is 2^N - 1, it directly relates to bit wise permutation
 *
 * COMPLEXITY:
 * Time:    O(2 ^ N)
 * Space:   O(2 ^ N)
 */

class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> res(1 << N);
        for(int mask = 0; mask < (1 << N); mask++) {
            int tmp = mask;
            while(tmp > 0) {
                res[mask].push_back(nums[countr_zero((unsigned int)tmp)]);
                tmp &= (tmp - 1);
            }
        }
        return res;
    }
};
