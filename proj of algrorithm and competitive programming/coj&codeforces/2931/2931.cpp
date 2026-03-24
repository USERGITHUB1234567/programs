#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
void sup2()
{
    int m,n,q;
    cin >> m >> n >> q;
    int max_row[m+1],col_row[m+1];
    int max_col[n+1],row_col[n+1];
    memset(max_row,0,sizeof(max_row));
    memset(max_col,0,sizeof(max_col));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int a;
            cin >> a;
            if(a>max_row[i]) {
                max_row[i]=a;
                col_row[i]=j;
            }
            if(a>max_col[j]) {
                max_col[j]=a;
                row_col[j]=i;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=m; i++) {
        if(max_row[i]==max_col[col_row[i]]) ans++;
    }
    while(q--) {
        int r,c,x;
        cin >> r >> c >> x;
        if(x>max_row[r]) {
            if(max_row[r]==max_col[col_row[r]]) ans--;
            max_row[r]=x;
            col_row[r]=c;
        }
        if(x>max_col[c]) {
            if(max_col[c]==max_row[row_col[c]]) ans--;
            max_col[c]=x;
            row_col[c]=r;
        }
        if(max_row[r]==x and max_col[c]==x) ans++;
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    /*ll m, n, q;
    cin >> m >> n >> q;
    vector<vector<ll>> a(m, vector<ll>(n));
    vector<ll> mr(m, LLONG_MIN), mc(n, LLONG_MIN);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            mr[i] = max(mr[i], a[i][j]);
            mc[j] = max(mc[j], a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == mr[i] && a[i][j] == mc[j]) {
                d++;
            }
        }
    }
    while (q--) {
        ll r, c, k;
        cin >> r >> c >> k;
        r--; c--;
        bool was_exploitable = (a[r][c] == mr[r] && a[r][c] == mc[c]);
        a[r][c] = k;
        if (k > mr[r]) mr[r] = k;
        if (k > mc[c]) mc[c] = k;
        if (!was_exploitable && k >= mr[r] && k >= mc[c]) {
            if (k == mr[r] && k == mc[c]) d++;
        } else if (was_exploitable && (k < mr[r] || k < mc[c])) {
            d--;
        }
        cout << d << "\n";
    }*/
    sup2();
    return 0;
}
