#include <bits/stdc++.h>
using namespace std;

/*
    @author breadOnLaptop
*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        const int N = arr.size();
        for(int i{}; i < N; i++) {
            for(int j{i + 1}; j < N; j++) {
                if(arr[i] >= arr[j]) {
                    arr[i] -= arr[j];
                    break;
                }
            }
        }

        return arr;
    }
};
