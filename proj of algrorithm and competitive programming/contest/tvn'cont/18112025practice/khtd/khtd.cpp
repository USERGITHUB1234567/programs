#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define foutput(name) freopen(name, "w", stdout);
#define finput(name) freopen(name,"r", stdin);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=100005,mod=1000000007;
long long fact[maxn],ifact[maxn];
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
int n,k;
long long a[maxn],b[maxn],f[maxn];
struct segtree {
    long long st[4*maxn];
    void init() {memset(st,0,sizeof(st));}
    inline void upd(int id, int l, int r, int i, long long v) {
        if(l>i || r<i) return;
        if(l==r) {st[id]=v;return;}
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
        st[id]=max(st[id<<1],st[id<<1|1]);
    }
    inline long long query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return max(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
    }
}seg;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("khtd")
    scanf("%d%d",&n,&k);
    seg.init();
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
    for(int i=1; i<=n; ++i) {
        int p=upper_bound(a+1,a+1+n,a[i]-k)-a;
        long long k1=(a[i]-k<a[1]?b[i]:seg.query(1,1,n,1,p-1)+b[i]),k2=seg.query(1,1,n,p,i);
        f[i]=max(k1,k2);
        //cout << p << ' ' << k1 << ' ' << k2 << '\n';
        seg.upd(1,1,n,i,f[i]);
    }
    //cout << '\n';
    //for(int i=1; i<=n; ++i) cout << f[i] << ' ';
    printf("%lld",f[n]);
    //seg.upd(1,1,n,1,1);seg.upd(1,1,n,2,5);
    //cout << seg.query(1,1,n,1,1);
    return 0;
}
/*
5 2 
1 2 3 4 5 
1 5 1 5 1 


*/