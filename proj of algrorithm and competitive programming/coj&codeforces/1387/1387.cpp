#include <bits/stdc++.h>
using namespace std;

const int DI[2][6] = {{0, -1, -1, 0, 1, 1}, {-1, -1, 0, 0, 1, 1}};
const int DJ[2][6] = {{-1, -1, 0, 1, 1, 0}, {0, 1, 1, -1, -1, 0}};
int m, n, w[501][501], d[502][502];
string a[501];
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    if ((m + n) % 2 == 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if ((i + j) % 2 == 0) {
                if (a[i][j] == '\\') w[i][j] = 0;
                else {
                    w[i][j] = 1;
                    a[i][j] = '\\';
                }
            } else {
                if (a[i][j] == '/') w[i][j] = 0;
                else {
                    w[i][j] = 1;
                    a[i][j] = '/';
                }
            }

    memset(d, 0, sizeof(d));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = -1;

    dq.push_back({1, 1});
    d[1][1] = w[1][1];

    while (!dq.empty()) {
        int i = dq.front().first, j = dq.front().second, t;
        dq.pop_front();
        if (a[i][j] == '\\') t = 0;
        else t = 1;

        for (int k = 0; k < 6; k++) {
            int r = i + DI[t][k];
            int c = j + DJ[t][k];
            if (d[r][c] == -1) {
                d[r][c] = d[i][j] + w[r][c];
                if (w[r][c] == 0)
                    dq.push_front({r, c});
                else
                    dq.push_back({r, c});
            }
        }

        if (d[m][n] != -1) {
            cout << d[m][n];
            return 0;
        }
    }

    return 0;
}
