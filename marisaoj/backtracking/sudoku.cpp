/**
 * @author  breadOnLaptop
 * @date 2026-10-04
 *
 * PLATFORM: MarisaOJ
 * QUESTION: Sudoku
 * LINK:     https://marisaoj.com/problem/57
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);

int board[9][9];
char row[9][9], col[9][9], box[3][3][9];

vector<vector<int>> LEFT;

void fillBoard(int cnt) {
    if(cnt == (int)LEFT.size()) {
        // print board;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(j) cout << ' ';
                cout << board[i][j];
            } cout << '\n';
        }
        exit(0);
    }

    int i = LEFT[cnt][0], j = LEFT[cnt][1];
    for(int v = 0; v < 9; v++) {
        if(row[i][v] == 0 && col[j][v] == 0 && box[i / 3][j / 3][v] == 0) {
            row[i][v] = col[j][v] = box[i / 3][j / 3][v] = 1;
            board[i][j] = v + 1;
            fillBoard(cnt + 1);
            row[i][v] = col[j][v] = box[i / 3][j / 3][v] = 0;
        }
    }
}

int main() {
    FASTIO

    memset(board, 0, sizeof(board));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(box, 0, sizeof(box));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                LEFT.push_back({i, j});
                continue;
            }

            int v = board[i][j] - 1;
            row[i][v] = col[j][v] = box[i / 3][j / 3][v] = 1;
        }
    }

    fillBoard(0);
    return 0;
 }
