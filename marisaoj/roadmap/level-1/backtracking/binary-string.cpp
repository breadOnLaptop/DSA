/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Binary String
 * LINK:     https://marisaoj.com/problem/543
 */

 #include <bits/stdc++.h>
 using namespace std;

 #define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

void backtrack (
    int i, string& s,
    const int& N
) {
    if(i == N) {
        cout << s << '\n';
        return;
    }

    backtrack(i + 1, s, N);

    s[i] = '1';
    backtrack(i + 1, s, N);
    s[i] = '0';
}

 int main() {
    FASTIO

    int N; cin >> N;
    string s(N, '0');

    backtrack(0, s, N);

    return 0;
 }
