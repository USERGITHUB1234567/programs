#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    int x, y;
};

bool inside(int x, int y, int x1, int x2, int y1, int y2) {
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}

int main() {
    int n;
    cin >> n;
    int xmin[27], xmax[27], ymin[27], ymax[27], x[27], y[27];
    for (int i = 1; i <= n; i++) cin >> xmin[i] >> xmax[i] >> ymin[i] >> ymax[i];
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    int a[27][27];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (inside(x[j], y[j], xmin[i], xmax[i], ymin[i], ymax[i])) {
                a[i][j] = 1;
                a[i][0]++;
                a[0][j]++;
            }
        }
    }
    vector<pair<int, int>> ans;
    bool stop = false;
    while (!stop) {
        stop = true;
        for (int i = 1; i <= n; i++) {
            if (a[i][0] == 1) {
                stop = false;
                for (int j = 1; j <= n; j++) {
                    if (a[i][j] == 1) {
                        ans.push_back({i, j});
                        for (int k = 1; k <= n; k++) {
                            if (a[k][j] == 1) {
                                a[k][j] = 0;
                                a[k][0]--;
                                a[0][j]--;
                            }
                        }
                        break;
                    }
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (a[0][j] == 1) {
                stop = false;
                for (int i = 1; i <= n; i++) {
                    if (a[i][j] == 1) {
                        ans.push_back({i, j});
                        for (int k = 1; k <= n; k++) {
                            if (a[i][k] == 1) {
                                a[i][k] = 0;
                                a[i][0]--;
                                a[0][k]--;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    if (ans.size() == 0) {
        cout << "none";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << char(ans[i].first + 'A' - 1) << " " << ans[i].second << "\n";
    }
    return 0;
}
