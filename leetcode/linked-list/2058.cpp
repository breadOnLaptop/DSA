#include <bits/stdc++.h>
using namespace std;

/*
    @author breadOnLaptop
    SUBMISSION: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/submissions/2125955200

    @brief
    TITLE: 2058. Find the Minimum Number of Nodes Between Critical Points

    TOPICS: Linked List

    PREREQUISITES: Linked List

    INTUITION:
    We need to find the critical points which we can refer to as Maxima and Minima as given in the question.
    The main intuition which we get the index differences in the form of {Minimum difference between Maxima/Minima, Maximum difference between Maxima/Minima}

    Thus we are only concerned with the indices when condition is satisfied.

    We know that the difference between latest index found or previous index specifically will have the highest probability of returning the minimum difference.
    And in the case of maximum difference, it can be found using the first index which we found as critical point to the most recent index we found, as they are logically far.

    DERIVATION:
    min_diff = min(min_diff, idx - back);
    max_diff = max(max_diff, idx - front);
    where back and front are [front, ...., back] and back will be updated each time new critical index is found.

    COMPLEXITY:
    Time:   O(n)
    Space:  O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_diff{INT_MAX}, max_diff{INT_MIN};
        int front{}, back{}, cnt{}, idx{};
        ListNode *prev = head;
        while(prev->next->next != nullptr) {
            int p = prev->val, c = prev->next->val, n = prev->next->next->val;
            if((p < c && c > n) || (p > c && c < n)) {
                if(!cnt) {
                    front = back = idx;
                } else {
                    min_diff = min(min_diff, idx - back);
                    max_diff = max(max_diff, idx - front);
                    back = idx;
                }

                cnt++;
            }

            idx++;
            prev = prev->next;
        }

        if(cnt < 2) return {-1, -1};
        return {min_diff, max_diff};
    }
};
