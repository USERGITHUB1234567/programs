#include <bits/stdc++.h>
using namespace std;

static const int N = 9;

bool rowUsed[N][10], colUsed[N][10], boxUsed[N][10];
int board[N][N];

// Convert (r,c) to box index 0…8
inline int boxIndex(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

bool solveSudoku(int r, int c) {
    if (r == N) // Finished all rows
        return true;
    int nr = (c == N - 1) ? r + 1 : r;
    int nc = (c == N - 1) ? 0 : c + 1;

    if (board[r][c] != 0)
        return solveSudoku(nr, nc);

    for (int val = 1; val <= 9; ++val) {
        int b = boxIndex(r, c);
        if (!rowUsed[r][val] && !colUsed[c][val] && !boxUsed[b][val]) {
            board[r][c] = val;
            rowUsed[r][val] = colUsed[c][val] = boxUsed[b][val] = true;

            if (solveSudoku(nr, nc))
                return true;

            // backtrack
            board[r][c] = 0;
            rowUsed[r][val] = colUsed[c][val] = boxUsed[b][val] = false;
        }
    }
    return false; // no valid number leads to a solution
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the puzzle: 9 lines with 9 digits each (0 = empty)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                int v = board[i][j];
                rowUsed[i][v] = true;
                colUsed[j][v] = true;
                boxUsed[boxIndex(i, j)][v] = true;
            }
        }
    }

    if (solveSudoku(0, 0)) {
        // Print solved board
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
