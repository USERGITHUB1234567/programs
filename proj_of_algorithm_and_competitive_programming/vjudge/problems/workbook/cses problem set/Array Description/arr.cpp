#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007,maxn=100005;
int n,m,x[maxn];
long long f[maxn][102];
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> x[i];
    if(x[1]) f[1][x[1]]=1;
    else for(int i=1; i<=m; ++i) f[1][i]=1;
    for(int i=2; i<=n; ++i) {
        if(x[i]) {
            f[i][x[i]]=(f[i-1][x[i]+1]+f[i-1][x[i]]+f[i-1][x[i]-1])%mod;

        }else {
            for(int j=1; j<=m; ++j) f[i][j]=(f[i-1][j+1]+f[i-1][j]+f[i-1][j-1])%mod;
        }
    }
    long long sum=0;
    for(int i=1; i<=m; ++i) sum=(sum+f[n][i])%mod;
    cout << sum;
}