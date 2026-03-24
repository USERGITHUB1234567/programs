#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const long long maxn=21,inf=LLONG_MAX;
long long n,k,c[maxn][maxn],f[1<<maxn],fm;
long long kq=inf;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("kronican");
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> c[i][j];
    }
    for(int i=0; i<(1<<n); i++) f[i]=inf;
    f[(1<<n)-1]=0;
    fm=1<<n;
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                c[i][j]=min(c[i][k]+c[k][j],c[i][j]);
            }
        }
    }
    for(int mask=fm-1; mask>=0; mask--) {
        if(__builtin_popcount(mask)<=k) continue;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mask&(1<<i) && mask&(1<<j) && i!=j) {
                    int nm=mask^(1<<i);
                    f[nm]=min(f[nm],f[mask]+c[i][j]);
                }
            }
        }
    }
    for(int mask=0; mask<fm; mask++) {
        if(__builtin_popcount(mask)==k) kq=min(kq,f[mask]);
    }
    cout << kq;
}