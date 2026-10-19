/**
 * @author  breadOnLaptop
 * @date    19th Sep 2026
 */

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    FASTIO

    int T = 1;
    int N;
    vector<string> grid;

    using NODE = pair<int, int>;

    enum class STATE {
        FORWARD_SLASH,
        BACKWARD_SLASH
    };

    NODE dirs[4] = {
        {-1, 0}, // up    [0]
        {0, -1}, // left  [1]
        {0, 1},  // right [2]
        {1, 0}   // down  [3]
    };

    auto check_coordinate = [&N](const int& i, const int& j) -> bool {
        return (0 <= i && i < N) && (0 <= j && j < N);
    };

    auto inverse_state = [&grid](const int& i, const int& j, const STATE& curr_state) -> void {
        if(curr_state == STATE::FORWARD_SLASH) {
            grid[i][j] = '\\';
        } else grid[i][j] = '/';
    };

    auto predict_next_move = [&dirs](const NODE& curr_dir, const STATE& state) -> NODE {
        if(curr_dir == dirs[0]) {
            return state == STATE::FORWARD_SLASH ? dirs[2] : dirs[1];
        } else if(curr_dir == dirs[1]) {
            return state == STATE::FORWARD_SLASH ? dirs[3] : dirs[0];
        } else if(curr_dir == dirs[2]) {
            return state == STATE::FORWARD_SLASH ? dirs[0] : dirs[3];
        }

        return state == STATE::FORWARD_SLASH ? dirs[1] : dirs[2];
    };

    // cin >> T;
    while(T--) {
        cin >> N;

        grid.resize(N);
        for(int i{}; i < N; i++) cin >> grid[i];

        int i = 0, j = 0;
        NODE curr_dir = dirs[3];
        int steps = 0;

        while(check_coordinate(i, j)) {
            steps++;

            if(grid[i][j] != '.') {
                STATE state = grid[i][j] == '/' ? STATE::FORWARD_SLASH : STATE::BACKWARD_SLASH;

                curr_dir = predict_next_move(curr_dir, state);
                inverse_state(i, j, state);
            }

            i += curr_dir.first;
            j += curr_dir.second;
        }

        cout << steps << '\n';
    }

    return 0;
}
