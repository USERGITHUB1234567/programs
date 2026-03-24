#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=5000006;
const long long inf=LLONG_MAX;
long long n,k,a[maxn],f[maxn];
struct segtree {
    long long st[4*maxn];
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]=f[l];
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=max(st[id<<1],st[id<<1|1]);
    }
    void upd(int id, int l, int r, int i, long long v) {
        if(l==r) {
            st[id]=v;
            return;
        }
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
        st[id]=max(st[id<<1],st[id<<1|1]);
    }
    long long query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return -inf;
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return max(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
    }
}seg;
void soup1() {
    long long kq=0;
    for(int i=1; i<=n; i++) if(a[i]>0) kq+=a[i];
    cout << kq;
} 
void soupfull() {
    for(int i=1; i<=n; i++) f[i]=-inf;
    f[1]=a[1];
    seg.upd(1,1,n,1,a[1]);
    for(int i=2; i<=n; i++) {
        //seg.upd(1,1,n,i,a[i]);
        int p=max(1LL,i-k);
        int m=seg.query(1,1,n,p,i-1);
        //cout << m << "\n";
        f[i]=max(f[i],m+a[i]);
        seg.upd(1,1,n,i,f[i]);
    }
    cout << f[n];
    //for(int i=1; i<=n; i++) cout << f[i] << " ";
    //cout << seg.query(1,1,n,1,3);
}
void soup() {
    deque<ll>dq;
    f[0]=0; 
    dq.push_back(1);
    for(int i=1; i<=n; i++) {
        while(!dq.empty() && i-dq.front()>k) dq.pop_front();
        if(!dq.empty()) {
            f[i]=f[dq.front()]+a[i];
        } 
        else {
            f[i]=a[i]; 
        }
        while(!dq.empty() && f[dq.back()]<=f[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << f[n];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("play")
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    if(k==n) {
        soup1();
        return 0;
    }
    //soupfull();
    soup();
}
/*
5 3
1 2 -2 -1 3

5 1
-5 -3 3 2 4
*/