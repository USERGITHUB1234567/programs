#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m, d, kq = 0;
int x[27];

struct ticket {
    int depart;
    int arriv;
    int gue_nu;
    int price;
    int near;
} a[26];

bool cmp(ticket a, ticket b) {
    if (a.depart != b.depart) return (a.depart < b.depart);
    return a.arriv < b.arriv;
}

void dfs(int i, int s) {
    if (i >= d) {
        kq = max(kq, s);
        return;
    }
    if (s + a[i].near <= kq) return;

    for (int j = 0; j <= 1; j++) {
        int k = a[i].depart;
        for (; k < a[i].arriv; k++) {
            x[k] += j * a[i].gue_nu;
            if (x[k] > n) break;
        }
        if (k == a[i].arriv) dfs(i + 1, s + j * a[i].price);
        for (k = min(k, a[i].arriv - 1); k >= a[i].depart; k--)
            x[k] -= j * a[i].gue_nu;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;
    for (int i = 0; i < d; i++) {
        cin >> a[i].depart >> a[i].arriv >> a[i].gue_nu;
        a[i].price = (a[i].arriv - a[i].depart) * a[i].gue_nu;
    }

    sort(a, a + d, cmp);

    a[d - 1].near = a[d - 1].price;
    for (int i = d - 2; i >= 0; i--) {
        a[i].near = a[i].price + a[i + 1].near;
    }

    memset(x, 0, sizeof(x));
    dfs(0, 0);

    cout << kq;
    return 0;
}
