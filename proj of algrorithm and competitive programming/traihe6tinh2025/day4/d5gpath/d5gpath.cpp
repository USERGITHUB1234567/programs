#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=2003;
int a[maxn][maxn],f[maxn][maxn][2];
int m,n;
vector<int>r,c;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> n;
    for(int i=1; i<=m; i++) {
        string s;
        cin >> s;
        for(int j=1; j<=n; j++) {
            a[i][j]=s[j-1]-48;
        }
    }
    f[1][1][0]=1-a[1][1];
    f[1][1][1]=a[1][1]+1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            for(int r=0; r<=1; r++) {
                int c=1^r^a[i][j];
                if(i>1 && j<=1) f[i][j][r]=f[i-1][j][1^c^a[i-1][j]]+r;
                else if(j>1 && i<=1) f[i][j][r]=f[i][j-1][r]+c;
                else if(i>1 && j>1)f[i][j][r]=min((f[i-1][j][1^c^a[i-1][j]])+r,f[i][j-1][r]+c);
            }
        }
    }
    int i=m,j=n,r;
    if(f[m][n][0]<f[m][n][1]) r=0;
    else r=1;
    while((i>1)||(j>1)) {
        if(i>1) {
            int c=1^r^a[i][j];
            if(f[i][j][r]==f[i-1][1^c^a[i][j]]) {
                r.push_back(i);
                i--;
                continue;
            }
        }
        else {

        }
    }
}
/*
2 2
10
10
*/
