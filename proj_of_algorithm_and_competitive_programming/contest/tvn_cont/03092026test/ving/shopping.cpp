#include <bits/stdc++.h>
using namespace std;
const int maxn=2003;
int n,a,b;
array<int,3>prod[maxn];
namespace soup1{
    int f[maxn][maxn];
    void implement() {
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<=a; ++j) {
                f[i][j]=f[i-1][j];
                if(j>=prod[i][1]) {
                    f[i][j]=max(f[i][j],f[i-1][j-prod[i][1]]+prod[i][0]);
                }
            }
        }
        cout << f[n][a];
    }
}
namespace soup4{
    int f[202][202][202];
    void implement() {
        for(int i=1; i<=n; ++i) {
            int mx=min(prod[i][1],b/prod[i][2]);
            for(int j=0; j<=a; ++j) for(int k=0; k<=b; ++k) f[i][j][k]=f[i-1][j][k];
            for(int d=0; d<=mx; ++d) {
                int cm=prod[i][1]-d,cv=prod[i][2]*d;
                for(int j=cm; j<=a; ++j) {
                    for(int k=cv; k<=b; ++k) {
                        //f[i][j][k]=f[i-1][j][k];
                        f[i][j][k]=max(f[i][j][k],f[i-1][j-cm][k-cv]+prod[i][0]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; ++i) for(int j=0; j<=a; ++j) for(int k=0; k<=b; ++k) ans=max(ans,f[i][j][k]);
        cout << ans;
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);
    cin >> n >> a >> b;
    for(int i=1; i<=n; ++i) cin >> prod[i][0] >> prod[i][1] >> prod[i][2];
    if(b==0) soup1::implement();
    //cout << '\n';
    else soup4::implement();
    //soup4::implement();
}