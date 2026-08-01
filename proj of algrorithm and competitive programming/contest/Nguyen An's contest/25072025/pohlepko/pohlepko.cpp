#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn = 2003;
string s[maxn];
int n, m;
int trace[maxn][maxn];

void soup1() {
    string kq = "";
    kq += s[0][0];
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (i == n - 1) {
            kq += s[i][j + 1];
            j++;
        } else if (j == m - 1) {
            kq += s[i + 1][j];
            i++;
        } else {
            if (s[i + 1][j] < s[i][j + 1]) {
                kq += s[i + 1][j];
                i++;
            } else {
                kq += s[i][j + 1];
                j++;
            }
        }
    }
    cout << kq;
}

void soup2() {
    vector<pair<int,int>> v, nv;
    v.emplace_back(0, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            trace[i][j] = 0;
    trace[0][0] = 1;
    string kq;
    kq += s[0][0];
    for (int step = 1; step < n + m - 1; step++) {
        char best = 'z' + 1;
        nv.clear();
        for (auto &p : v) {
            int x = p.first, y = p.second;
            if (x + 1 < n && !trace[x+1][y]) {
                trace[x+1][y] = 1;
                nv.emplace_back(x+1, y);
                best = min(best, s[x+1][y]);
            }
            if (y + 1 < m && !trace[x][y+1]) {
                trace[x][y+1] = 1;
                nv.emplace_back(x, y+1);
                best = min(best, s[x][y+1]);
            }
        }

        kq += best;
        v.clear();
        for (auto &p : nv) {
            int x = p.first, y = p.second;
            if (s[x][y] == best) {
                v.emplace_back(x, y);
            } else {
                trace[x][y] = 0;
            }
        }
    }

    cout << kq;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    soup2();
    return 0;
}
