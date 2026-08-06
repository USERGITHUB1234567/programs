#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int n, k;
int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (freopen("bando.inp", "r", stdin)) {
        freopen("bando.out", "w", stdout);
    }

    if (!(cin >> n >> k)) return 0;

    // Ban dau moi nep gap tu 0 den N deu co 1 layer
    for (int i = 0; i <= n; ++i) {
        cnt[i] = 1;
    }

    int L = 0, R = n;

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;

        // Nep gap x phai nam trong phan ban do hien tai [L, R]
        if (x <= L || x >= R) continue;

        int len_left = x - L;
        int len_right = R - x;

        // Truong hop 1: Nua trai ngan hon hoac bang nua phai (gap trai len phai)
        if (len_left <= len_right) {
            for (int j = 1; j <= len_left; ++j) {
                cnt[x + j] += cnt[x - j];
            }
            L = x;
        } 
        // Truong hop 2: Nua phai ngan hon nua trai (gap phai len trai)
        else {
            for (int j = 1; j <= len_right; ++j) {
                cnt[x - j] += cnt[x + j];
            }
            R = x;
        }
    }

    // In ra so luong nep gap con lai va so layer tai moi nep gap
    cout << R - L + 1 << "\n";
    for (int i = L; i <= R; ++i) {
        cout << cnt[i] << (i == R ? "" : " ");
    }
    cout << "\n";

    return 0;
}