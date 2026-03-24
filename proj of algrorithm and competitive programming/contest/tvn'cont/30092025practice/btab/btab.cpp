#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
static const int maxd=1003;
typedef long long ll;
typedef long double ld;
const int maxn=1003,mod=1000000007;
int n,a[maxn][maxn],b[maxn][maxn],pre[maxn][maxn];
namespace soup1 {
    void solve() {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                for(int k=1; k<=n; ++k) b[i][j]+=a[i][k]+a[k][j];
                b[i][j]-=a[i][j];
            }
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) cout << b[i][j] << ' ';
            cout << "\n";
        }
    }
}
namespace soup2 {
    long long query(int i, int j,int k, int t) {
        return pre[k][t]-pre[k][j-1]-pre[i-1][t]+pre[i-1][j-1];
    }
    void solve() {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+a[i][j]-pre[i-1][j-1];
            }
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                b[i][j]=pre[n][n]-query(1,1,i-1,j-1)-query(i+1,1,n,j-1)-query(1,j+1,i-1,n)-query(i+1,j+1,n,n);
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("btab")
    cin >> n;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) cin >> a[i][j];
    }
    if(n<=200) {
        soup1::solve();
        return 0;
    }
    soup2::solve();
    return 0;
}
/*
3
1 2 3
4 5 6
7 8 9
*/