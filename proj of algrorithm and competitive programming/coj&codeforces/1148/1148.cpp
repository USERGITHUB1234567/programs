#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int x[30];
int main()
{
    int n,m,v[26],a[16][26];
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    cin >> m;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    int ans=m+1,res;
    for(int i=0; i<(1<<m); i++) {
        bool ok=true;
        for(int j=1; j<=n; j++) {
            int s=0;
            for(int k=1; k<=m; k++)
                if(((i>>(k-1))&1)==1)
                    s+=a[k][j];
            if(s<v[i]) {
                ok=false;
                break;
            }
        }
        if(ok) {
            int cnt=0;
            for(int j=0; j<m; j++)
                if(((i>>j)&1)==1)
                cnt++;
            if(cnt<ans) {
                ans=cnt;
                res=i;
            }
        }
    }
    cout << ans;
    for(int i=1; i<=m; i++) {
        if(((res>>(i-1))&1)==1) cout << " " << i;
    }
    return 0;
}
