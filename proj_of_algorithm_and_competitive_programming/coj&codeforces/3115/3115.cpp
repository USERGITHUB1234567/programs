#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=10;
int a[maxn][maxn],n,kq=0,cnt=0,k;
bool col[maxn], diag1[2 * maxn], diag2[2 * maxn];
void dfs(int u, int sum) {
    if(u==n+1) {
        if (cnt>k) return;
        kq=max(kq, sum);
        return;
    }
    for (int i=1; i<=n; i++) {
        int d1=u-i+n;
        int d2=u+i;
        if (!col[i] && !diag1[d1] && !diag2[d2]) {
            col[i]=diag1[d1]=diag2[d2]=true;
            cnt++;
            dfs(u+1, sum+a[u][i]);
            cnt--;
            col[i]=diag1[d1]=diag2[d2]=false;
        }
    }
    dfs(u+1,sum);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    dfs(1,0);
    cout << kq;
}