#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fti(i, x, y) for (int i = x; i <= y; ++i)
#define ftd(i, x, y) for (int i = x; i >= y; --i)

const int MA = 1e5 + 5;

int n, m, d, res = 0;
vector <int> con[MA];
string s[MA];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("museum.inp", "r", stdin);
    freopen("museum.out", "w", stdout);
    cin >> n >> m >> d;
    fti(i, 1, m)
    {
        int u, v; cin >> u >> v;
        con[u].push_back(v);
    }
    fti(i, 1, n) cin >> s[i];
    if (m == 0)
    {
        bool ok = 0;
        fti(i, 0, d - 1)
            if (s[1][i] == '1')
            {
                ok = 1; break;
            }
        cout << ok;
    }
    else
    {
        int cnt = 0;
        fti(i, 1, n)
            fti(j, 0, d - 1)
                if (s[i][j] == '1')
                {
                    ++cnt; break;
                }
        cout << cnt;
    }
    return 0;
}
