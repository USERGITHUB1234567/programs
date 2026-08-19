#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define int long long
using namespace std;
const int maxn=6003;
int a,b,c,d,e,pre[maxn][maxn],kq=0;
bool mk[maxn][maxn];
void setup() {
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+mk[i][j];
        }
    }
}
int get(int i, int j, int u, int v) {
    return pre[u][v]-pre[i-1][v]-pre[u][j-1]+pre[i-1][j-1];
}
void soup2() {
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            for(int k=1; i+k-1<=a && j+k-1<=b; k++) {
                if((k)%d!=0) continue;
                int u=i+k-1,v=j+k-1;
                int t=get(i,j,u,v);
                if(t<=e) kq=max(kq,k);
            }
        }
    }
    cout << kq;
}
bool check(int mid) {
    int n=a-mid+1,m=b-mid+1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int u=i+mid-1,v=j+mid-1;
            if(get(i,j,u,v)<=e) {
                kq=mid;
                return true;
            }
        }
    }
    return false;
}
void soupfull() {
    int l=0,r=min(a,b)/d;
    while(l<=r) {
        int m=(l+r)>>1;
        if(check(m*d)) l=m+1;
        else r=m-1;
    }
    cout << kq;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("paper")
    memset(mk,false,sizeof(mk));
    cin >> a >> b >> c >> d >> e;
    for(int i=1; i<=c; i++) {
        int u,v;
        cin >> u >> v;
        mk[u][v]=true;
    }
    setup();
    soupfull();
}