/**
 * @author  breadOnLaptop
 * @date    27th Sep 2026
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Knight's Tour
 * LINK:     https://marisaoj.com/problem/324
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N, M;
int board[7][7];

constexpr int MOVE_SET[8][2] {
    {-2, -1}, {-1, -2}, {-1, 2}, {-2, 1},
    {2, -1}, {1, -2}, {1, 2}, {2, 1}
};

void generateBoard(int i, int j, int steps) {
    if(steps == N * M) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(j) cout << ' ';
                cout << board[i][j];
            } cout << '\n';
        }

        exit(0);
    }

    for(int k = 0; k < 8; k++) {
        int ni = i + MOVE_SET[k][0], nj = j + MOVE_SET[k][1];

        if(0<= ni && ni < N && 0 <= nj && nj < M && board[ni][nj] == 0) {
            board[ni][nj] = steps + 1;
            generateBoard(ni, nj, steps + 1);
            board[ni][nj] = 0;
        }
    }
}

int main() {
    FASTIO

    cin >> N >> M;
    memset(board, 0, sizeof(board));

    board[0][0] = 1;
    generateBoard(0, 0, 1);

    return 0;
 }
