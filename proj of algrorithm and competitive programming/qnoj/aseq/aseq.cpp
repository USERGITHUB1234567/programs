#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
long long n,l,r,a[maxn],pre[maxn];
int kq=0;
struct segtree {
    struct node {
        int v,l,r;
    }st[4*maxn];
    bool leaf[4*maxn];
    void init() {
        for(int i=0; i<4*maxn; i++) leaf[i]=false;
    }
    void build(int id, int ql, int qr) {
        if(l==r) {
            st[id].v=a[l];
            leaf[id]=true;
            return;
        }
        int m=(ql+qr)>>1;
        build(id<<1,ql,m);
        build(id<<1|1,m+1, qr);
        st[id].v=st[id<<1].v+st[id<<1|1].v;
        st[id].l=st[id<<1].v;
        st[id].r=st[id<<1|1].v;
    }
    void query(int id, int ql, int qr, int i, int j) {
        if(ql>j || qr<i) return;
        if(ql==qr) {
            if(st[id].v>=l && st[id].v<=r) kq++;
            return;
        }
        if(ql>=i && qr<=j && st[id].v>=l && st[id].v<=r) kq++; 
        if(!leaf[id<<1] && !leaf[id<<1|1]) {
            int sum=st[id<<1].l+st[id<<1|1].r;
            if(sum>=l && sum<=r) kq++;
        }
        int m=(l+r)>>1;
        query(id<<1,l,m,i,j);
        query(id<<1|1,m+1,r,i,j);
    }
} seg;
void soup1() {
    long long kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(abs(-pre[i-1]+pre[j])>=l && abs(pre[j]-pre[i-1]<=r)) kq++;
        }
    }
    cout << kq;
}
void soupfull() {
    //int kq=0;
    /*for(int i=1; i<=n; i++) {

    }*/
   seg.init();
   seg.build(1,1,n);
   seg.query(1,1,n,1,n);
   cout << kq;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> l >> r;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    if(n<=1000) {
        soup1();
        return 0;
    }
    soupfull();
}