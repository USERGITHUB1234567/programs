#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=50004;
int n,m,s,ans=0;
int mk[2*maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> n >> s;
    int a[m+1][n+1];
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=s; i++) {
        int x;
        cin >> x;
        mk[x]++;
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int fn=(a[i][j]+mk[i]+mk[m+j])%3;
            if(fn==0) ans++;
        }
    }
    cout << ans;
}
/*
2 3 0
0 0 0
0 0 2

2 3 2
0 0 0
0 0 2
2 3
*/
