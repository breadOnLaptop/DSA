#include <bits/stdc++.h>
using namespace std;

/*
    @author breadOnLaptop
    BEST SUBMISSION: https://leetcode.com/problems/subsets-ii/submissions/2125874940

    @brief
    TITLE: 90. Subsets II

    TOPICS: Recursion

    PREREQUISITES: Sorting, Decision Branching [Take and Not Take specifically]

    FOLLOWUP:
    78. Subsets [Now Duplicates are allowed]

    INTUITION:
    Questions Approach is similar to the it's previous question [78. Subsets], but now it requires to handle the subset
    generation with duplicate values.
    We can use the same method of insertion and finding the subset but after the considering the elements we must ignore it's different indexed occurrences.

    DERIVATION:
    From the provided intuition we can derive the introduction of a index skip method:
    After pushing every indexed elements in current generated subset we need to skip it for other subsets.
    This can be done using line number [51]. This skips the already used duplicates

    COMPLEXITY:
    Time:   O(n * logn + n * 2 ^ n)
    Space:  O(n * 2 ^ n)
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int N = nums.size();
        vector<int> curr;
        vector<vector<int>> res;
        auto generator = [&N, &curr, &res, &nums](auto&& self, int i) mutable -> void {
            if(i == N) {
                res.push_back(curr);
                return;
            }

            curr.push_back(nums[i]);
            self(self, i + 1);
            curr.pop_back();

            while(i + 1 < N && nums[i + 1] == nums[i]) ++i;

            self(self, i + 1);
        };

        generator(generator, 0);

        return res;
    }
};
