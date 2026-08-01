#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, xp, c[14][14], x[14], y[14], min_fx=1e9, c_min=1e9;
bool used[14];
void dfs(int i, int s)
{
    if(i>n) {
        if(min_fx>s+c[x[n]][xp]) {
            min_fx=s+c[x[n]][xp];
            copy(x+1,x+1+n,y+1);
        }
        return;
    }
    for(int j=1; j<=n; j++) {
        int t=s+c[x[i-1]][j];
        if(!used[j] and t+(n-i+1)*c_min<min_fx) {
            x[i]=j;
            used[j]=true;
            dfs(i+1,t);
            used[j]=false;
        }
    }
}
int main()
{
    cin >> n >> xp;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> c[i][j];
            c_min=min(c_min,c[i][j]);
        }
    }
    memset(used,false,sizeof(used));
    x[1]=xp;
    used[xp]=true;
    dfs(2,0);
    cout << min_fx << "\n";
    for(int i=1; i<=n; i++) {
        cout << y[i];
        if(i!=n) cout << " ";
    }
    return 0;
}
