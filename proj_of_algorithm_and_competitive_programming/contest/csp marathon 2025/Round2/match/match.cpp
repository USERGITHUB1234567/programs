#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int maxn=1000006;
int n,m,q,a[maxn],b[maxn];
bool vis[maxn],mk[maxn];
bool kt(int l, int r)
{
    int cur=0;
    for(int i=l; i<=r; i++) {
        if(a[i]==cur+1) {
            cur=a[i];
            if(cur==m) return true;
        }
        vis[i]=true;
    }
    if(cur==m) return true;
    for(int i=l; i<=r; i++) {
        if(vis[i]) break;
        if(a[i]==cur+1) {
            cur=a[i];
            if(cur==m) return true;
        }
    }
    return(cur==m);
}
void soup1()
{
    for(int i=1; i<=q; i++) {
        int l,r;
        for(int j=l; j<=r; j++) vis[i]=false;
        cin >> l >> r;
        cout << (kt(l,r)?"YES\n":"NO\n");
    }
}
void soup2()
{
    for(int i=1; i+m-1<=n; i++) {
        mk[i]=kt(i,i+m-1);
    }
    for(int i=1; i<=q; i++) {
        int l,r;
        cin >> l >> r;
        cout << (mk[l]?"YES\n":"NO\n");
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("match");
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];
    if(q<=10 && n<=1000 && m<=1000) {
        soup1();
        return 0;
    }
    soup2();
}
