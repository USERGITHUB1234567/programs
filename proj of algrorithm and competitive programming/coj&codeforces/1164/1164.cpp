#include <bits/stdc++.h>
using namespace std;

int m, n, a[31][31], cnt = 0, it[27], jt[27], id[27], jd[27], frame[27];
bool used[27], tren[27][27];

void dfs(int i) {
    if (i > cnt) {
        for (int j = 1; j <= cnt; j++) {
            cout << char('A' + frame[j] - 1);
        }
        cout << "\n";
        return;
    }

    for (int j = 1; j <= 26; j++)
        if (!used[j]) {
            int k = 1;
            for (; k <= 26; k++)
                if (!used[k] && tren[j][k]) break;
            if (k <= 26) continue;
            frame[i] = j;
            used[j] = true;
            dfs(i + 1);
            used[j] = false;
        }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("1164.inp", "r", stdin);
    //freopen("1164.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '.')
                a[i][j] = 0;
            else
                a[i][j] = c - 'A' + 1;
        }

    // Tìm tọa độ đỉnh trên trái (it, jt) và dưới phải (id, jd) của mỗi khung
    memset(used, false, sizeof(used));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 0) {
                if (!used[a[i][j]]) {
                    cnt++;
                    used[a[i][j]] = true;
                    it[a[i][j]] = i;
                    jt[a[i][j]] = j;
                    id[a[i][j]] = i;
                    jd[a[i][j]] = j;
                } else {
                    it[a[i][j]] = min(it[a[i][j]], i);
                    jt[a[i][j]] = min(jt[a[i][j]], j);
                    id[a[i][j]] = max(id[a[i][j]], i);
                    jd[a[i][j]] = max(jd[a[i][j]], j);
                }
            }

    // tren[i][j] = true nếu khung i nằm trên khung j
    memset(tren, false, sizeof(tren));
    for (int k = 1; k <= 26; k++)
        if (used[k]) {
            // Cạnh trên
            for (int j = jt[k]; j <= jd[k]; j++)
                if (a[it[k]][j] != 0 && a[it[k]][j] != k)
                    tren[a[it[k]][j]][k] = true;

            // Cạnh phải
            for (int i = it[k]; i <= id[k]; i++)
                if (a[i][jd[k]] != 0 && a[i][jd[k]] != k)
                    tren[a[i][jd[k]]][k] = true;

            // Cạnh dưới
            for (int j = jd[k]; j >= jt[k]; j--)
                if (a[id[k]][j] != 0 && a[id[k]][j] != k)
                    tren[a[id[k]][j]][k] = true;

            // Cạnh trái
            for (int i = id[k]; i >= it[k]; i--)
                if (a[i][jt[k]] != 0 && a[i][jt[k]] != k)
                    tren[a[i][jt[k]]][k] = true;
        }

    for (int i = 1; i <= 26; i++)
        used[i] = !used[i];
    dfs(1);
    return 0;
}
