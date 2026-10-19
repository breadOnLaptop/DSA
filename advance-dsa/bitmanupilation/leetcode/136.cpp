#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date 2026-10-11
 *
 * @brief
 * TITLE: 136. Single Number
 *
 * TOPICS: Bit Manupilation
 *
 * PREREQUISITES: XOR
 *
 * INTUITION: Use XOR which can reveal the duplicated values, sinc its properties are:
 * - A ^ B = B ^ A
 * - A ^ A = 0
 *
 * COMPLEXITY:
 * Time:    O(N)
 * Space:   O(1)
 */

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int mask = 0;
        for(const int& i : nums) mask ^= i;

        return mask;
    }
};
