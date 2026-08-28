#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/submissions/2123245747
 *
 * @brief
 * 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
 *
 * FOLLOW UP FROM:
 * 3720. Lexicographically Smallest Permutation Greater Than Target.
 * https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/submissions/2121899743
 *
 * INTUITION:
 * Instead of checking each time if the formed string is palindrome or not which will cost O(N * N!) [TREMENDOUS]
 * We need to create a best possible palindromic string which is lexicographically larger and closest to the [target] string
 *
 * TOPICS: Enumeration, string, Hash Table, Backtracking, Pruning
 *
 * PREREQUISITES: Palindrome, Hashing and Recursion
 *
 * INTUITION:
 * Instead of checking the resultant candidate string palindrome. We need to generate the closest largest palindrome string.
 * We use the idea of generating the palindrome by checking if the current choice of character can be placed at index of i and N - i - 1
 * There is a catch.
 * We need to determine the states which are possible while generating the resultant string.
 * The states which we can think of are:
 * - choice > target[i] : POSSIBLE we can find the string from here
 * - choice == target[i] but then: choice > target[N - i - 1] : POSSIBLE, this means it is lexicographically bigger
 * - choice == target[i] but then: choice <= target[N - i - 1] : NOT_POSSIBLE
 * - choice < target[i] : NOT_POSSIBLE
 *
 * DERIVATION: As we know lexicographically largest means from left to right the current string should be greater than target
 * string. We can have the left side equal to but right side should be as big as possible.
 *
 * COMPLEXITIES:
 * Time: O(26 * N / 2)
 * Space: O(N)
 */

class Solution {
  public:
  string lexPalindromicPermutation(string s, string target) {
    const int N = s.size();

    // Possible states for two strings evaluations
    const enum class STATE {
      NOT_POSSIBLE,
      POSSIBLE,
      MAYBE,
      FINALLY_NOT_POSSIBLE
    };

    int memo[26]{};
    for(const char& c : s) memo[c - 'a']++;

    /**
     * @brief Resultant string generator using backtrack using lambda recursive function
     *
     * @param
     * string [generating current], int [index], STATE [current state of the generated string]
     */
    char found = 0;
    string res = "";
    auto backtrack = [&N, &s, &target, &res, &memo, &found](auto&& self, string& curr, int i, STATE curr_state) mutable -> void {
      if(found) return;
      if(i == N / 2) {
        if(N & 1) {
          char candidate;
          for(int j{}; j < 26; j++) if(memo[j]) {
            candidate = 'a' + j;
            break;
          }

          curr[i] = candidate;
          if(curr_state != STATE::POSSIBLE) {
            if(candidate > target[i]) curr_state = STATE::POSSIBLE;
            else if(candidate < target[i]) curr_state = STATE::FINALLY_NOT_POSSIBLE;
          }
        }

        if(curr_state == STATE::POSSIBLE || curr_state == STATE::MAYBE) {
          res = curr;
          found = 1;
        }

        return;
      }

      for(int j{}; j < 26; j++) {
        if(memo[j] >= 2) {
          const char choice = 'a' + j;
          if(curr_state != STATE::POSSIBLE && choice < target[i]) continue;

          memo[j] -= 2;
          curr[i] = curr[N - i - 1] = choice;

          STATE next_state = curr_state;
          if(curr_state != STATE::POSSIBLE) {
            if(choice > target[i]) next_state = STATE::POSSIBLE;
            else if(choice == target[i]) {
              if(choice > target[N - i - 1]) next_state = STATE::MAYBE;
              else if(choice < target[N - i - 1]) next_state = STATE::FINALLY_NOT_POSSIBLE;
            }
          }
          self(self, curr, i + 1, next_state);

          memo[j] += 2;
          curr[i] = curr[N - i - 1] = ' ';

          if(next_state == STATE::POSSIBLE) break;
        }
      }
    };

    STATE state = STATE::NOT_POSSIBLE;
    string curr = string(N, ' ');
    backtrack(backtrack, curr, 0, state);

    return res;
  }
};
