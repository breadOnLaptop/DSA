/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: ABC string
 * LINK:     https://marisaoj.com/problem/544
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

void generateString(string& s, const int& N) {
    if((int)s.size() == N) {
        cout << s << '\n';
        return;
    }

    for(const char& c : {'A', 'B', 'C'}) {
        if(!s.empty() && s.back() == c) continue;

        s += c;
        generateString(s, N);
        s.pop_back();
    }
}

int main() {
    FASTIO

    int N;
    string s;

    cin >> N;
    generateString(s, N);

    return 0;
 }
