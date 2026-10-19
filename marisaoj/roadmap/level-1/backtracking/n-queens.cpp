/**
 * @author  breadOnLaptop
 * @date    3rd Oct 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: N Queens
 * LINK:     https://marisaoj.com/problem/53
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int N, cnt = 0;
char board[10];
char col[10], mainD[19], antiD[19];

void generateBoard(int r) {
    if(r == N) {
        ++cnt;
        return;
    }

    for(int c = 0; c < N; c++) {
        int main_idx = r - c + (N - 1);
        int anti_idx = r + c;

        if(col[c] == 0 && mainD[main_idx] == 0 && antiD[anti_idx] == 0) {
            board[c] = col[c] = 1;
            mainD[main_idx] = antiD[anti_idx] = 1;

            generateBoard(r + 1);

            board[c] = col[c] = 0;
            mainD[main_idx] = antiD[anti_idx] = 0;
        }
    }
}

int main() {
    FASTIO

    cin >> N;
    memset(board, 0, sizeof(board));
    memset(col, 0, sizeof(col));
    memset(mainD, 0, sizeof(mainD));
    memset(antiD, 0, sizeof(antiD));

    generateBoard(0);
    cout << cnt << '\n';

    return 0;
 }
