#include <bits/stdc++.h>
using namespace std;
const int maxn=1003,mod=1000000007;
int n;
char grid[maxn][maxn];
long long f[maxn][maxn];
int main(int argc, char** argv) {
    cin >> n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) cin >> grid[i][j];
    f[1][1]=(grid[1][1]=='.');
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(i==1 && j==1 || grid[i][j]=='*') continue;
            f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
        }
    }
    cout << f[n][n];
}