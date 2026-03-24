#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,f[21][21];
bool kt=false;
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cin >> f[i][j];
    }
    for(int i=1; i<n; i++) {
        bool va=true;
        for(int j=1; j<=m; j++) {
            if(f[i][j]==f[i+1][j]) {
                va=false;
                break;
            }
        }
        if(va) {
            kt=true;
            break;
        }
    }
    for(int j=1; j<m; j++) {
        bool va=true;
        for(int i=1; i<=n; i++) {
            if(f[i][j]==f[i][j+1]) {
                va=false;
                break;
            }
        }
        if(va) {
            kt=true;
            break;
        }
    }
    if(kt) cout << "Yes";
    else cout << "No";
}
