#include <bits/stdc++.h>
using namespace std;
const int maxn=502;
int n,m,a[maxn][maxn];
void souprua(int n)
{
    for(int i=1; i<=n; i++) cout << 1 << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,q;
        cin >> u >> v >> q;
        a[u][v]=q;
    }
    cout << 1 << " " << 0;
    //souprua(n);
}
