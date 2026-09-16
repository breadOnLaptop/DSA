/**
 * @author  breadOnLaptop
 * @date    16th Sep 2026
 *
 * SUBMISSION: https://cses.fi/paste/b5f3ce21c43e5a0d11e4d36/
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO  ios::sync_with_stdio(false); \
                cin.tie(nullptr);

int main() {
    FASTIO

    int N, M;
    const char START = 'A', END = 'B', STOP = '#';
    auto check_coordinate = [&N, &M](const int& i, const int& j) -> bool {
        return (0 <= i && i < N) && (0 <= j && j < M);
    };

    auto get_move = [](const int& i, const int& j) -> char {
        if(i == 0 && j == 1) return 'R';
        else if(i == 1 && j == 0) return 'D';
        else if(i == -1 && j == 0) return 'U';
        return 'L';
    };

    int T = 1;
    // cin >> T;
    while(T--) {
        cin >> N >> M;
        vector<string> grid(N); for(auto& row : grid) cin >> row;

        // cout << "GRID\n";
        // for(const string& row : grid) {
        //     for(int j{}; j < M; j++) {
        //         if(j) cout << ' ';
        //         cout << row[j];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        using NODE = pair<int, int>;
        NODE dirs[4] = {
            {0, 1}, {-1, 0}, // [DOWN], [LEFT]
            {1, 0}, {0, -1}  // [RIGHT], [UP]
        };

        NODE start, end;
        for(int i{}; i < N; i++) {
            for(int j{}; j < M; j++) {
                if(grid[i][j] == START) start = NODE{i, j};
                else if(grid[i][j] == END) end = NODE{i, j};
            }
        }

        // cout << '[' << start.first << ", " << start.second << ']'  << ' ' << '[' << end.first << ", " << end.second << ']' << '\n';

        queue<NODE> q;
        vector<vector<char>> step(N, vector<char>(M, 0));
        q.push(start);
        step[start.first][start.second] = 'S';
        while(!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if(i == end.first && j == end.second) break;

            for(const auto& [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if(!check_coordinate(ni, nj) || step[ni][nj] || grid[ni][nj] == STOP) continue;

                step[ni][nj] = get_move(di, dj);
                q.push(NODE{ni, nj});
            }
        }

        if(!step[end.first][end.second]) {
            cout << "NO\n";
            return 0;
        }

        string path = "";
        NODE curr = end;
        while(curr != start) {
            char ch = step[curr.first][curr.second];

            path += ch;

            if(ch == 'D') --curr.first;
            else if(ch == 'U') ++curr.first;
            else if(ch == 'L') ++curr.second;
            else --curr.second;
        }

        reverse(path.begin(), path.end());

        cout << "YES\n";
        cout << path.size() << '\n' << path << '\n';
    }

    return 0;
}
