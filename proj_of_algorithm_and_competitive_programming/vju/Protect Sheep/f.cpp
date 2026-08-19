#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int R, C;
char grid[505][505];

bool isSafe() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'S') {
                if ((i > 0 && grid[i - 1][j] == 'W') || (i < R - 1 && grid[i + 1][j] == 'W') ||
                    (j > 0 && grid[i][j - 1] == 'W') || (j < C - 1 && grid[i][j + 1] == 'W')) {
                    return false;
                }
            }
        }
    }
    return true;
}

void placeDogs() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'D';
            }
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    if (!isSafe()) {
        cout << "No" << endl;
    } else {
        placeDogs();
        cout << "Yes" << endl;
        for (int i = 0; i < R; ++i) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}
