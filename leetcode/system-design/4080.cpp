/**
 * @author  breadOnLaptop
 * @date 2026-10-21
 *
 * PLATFORM: LeetCode
 * TITLE: 4080. Design Bus Seat Booking System
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()

class BusBooking {
    private:
    int m, n;
    vector<vector<char>> A;

    public:
    BusBooking(int nn) {
        A.assign(nn + 1, vector<char>(4, 0));
        m = n = 0;
    }

    void toggle(string seat) {
        int j = seat[0] - 'A';
        int i = stoi(seat.substr(1, seat.size()));

        if(A[i][j] == 0) {
            if(j == 0) A[i][j] = A[i][j + 1] == 1 ? 3 : 1;
            else if(j == 3) A[i][j] = A[i][j - 1] == 1 ? 3 : 1;
            else A[i][j] = 1;

            m += A[i][j];
            n += 1;
        } else {
            m -= A[i][j];
            n -= 1;
            
            A[i][j] = 0;
        }
    }

    int getTotalTime() {
        return m;
    }

    int getMinTime() {
        return n;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
