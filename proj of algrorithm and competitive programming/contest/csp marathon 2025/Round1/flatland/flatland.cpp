#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn=1003;
int a[maxn][maxn],n,m,pre[maxn][maxn];
void sub1()
{
    int kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int k=i; k<=n; k++) {
                for(int t=j; t<=m; t++) {
                    bool ck=true;
                    int m=a[i][j];
                    for(int q=i; q<=k; q++) {
                        for(int p=j; p<=t; p++) {
                            if(a[q][p]!=m) {
                                ck=false;
                                break;
                            }
                        }
                    }
                    if(ck) {
                        kq=max(2*(abs(k-i+1)+abs(t-j+1)),kq);
                    }
                }
            }
        }
    }
    cout << kq;
}
void sub2()
{
    int kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int k=i; k<=n; k++) {
                for(int t=j; t<=m; t++) {
                    int s=pre[k][t]-(pre[i-1][t]+pre[k][j-1]-pre[i-1][j-1]);
                    if(s/((abs(k-i)+1)*(abs(t-j)+1))==1) {
                        kq=max(kq,2*(abs(k-i+1)+abs(t-j+1)));
                        //cout << i << " " << j << " " << k << " " << t << "\n";
                    }
                    else if(s==0) {
                        kq=max(kq,2*(abs(k-i+1)+abs(t-j+1)));
                        //cout << i << " " << j << " " << k << " " << t << "\n";
                    }
                }
            }
        }
    }
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //freopen("flatland.inp", "r", stdin);
    //freopen("flatland.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }
    if(n<=500) sub1();
    sub2();
}
