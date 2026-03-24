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
const int maxn=100005,inf=INT_MAX,mod=1000000007;
int t,n,q,a[maxn];
struct segtree {
    pair<int,int> st[4*maxn];
    pair<int,int>merge(pair<int,int>l, pair<int,int>r) {
        if(l.fi<r.fi) return l;
        else if(l.fi>r.fi) return r;
        return {l.fi,l.se+r.se};
    }
    void build(int id, int l, int r) {
        if(l==r) {
            st[id].fi=a[l];
            st[id].se=1;
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=merge(st[id<<1],st[id<<1|1]);
    }
    void upd(int id, int l, int r, int i, int v) {
        if(l>i || r<i) return;
        if(l==r) {
            st[id]={v,1};
            return;
        }
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
        st[id]=merge(st[id<<1],st[id<<1|1]);
    }
    pair<int,int> query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return {inf,0};
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        pair<int,int>left=query(id<<1,l,m,i,j),right=query(id<<1|1,m+1,r,i,j);
        return merge(left,right);
    }
    int walk(int id, int l, int r, int i, int j, int v) {
        if(l>j || r<i || st[id].fi>v) return -1;
        if(l==r) {
            if(st[id].fi==v) return l;
            return -1;
        } 
        int m=(l+r)>>1,res=-1;
        if(st[id<<1].fi<=v && i<=m) res=walk(id<<1,l,m,i,j,v);
        if(res==-1) {
            if(st[id<<1|1].fi<=v && j>m) res=walk(id<<1|1,m+1,r,i,j,v);
        }
        return res;
    }
}seg;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i=1; i<=n; i++) cin >> a[i];
        seg.build(1,1,n);
        long long ans=0;
        while(q--) {
            int ty;
            cin >> ty;
            if(ty==1) {
                int x,y;
                cin >> x >> y;
                a[x]=y;
                seg.upd(1,1,n,x,y);
                //for(int i=1; i<=n; i++) cout << a[i] << " ";
                //cout << "\n";
            }
            else {
                int l,r;
                cin >> l >> r;
                pair<int,int>k=seg.query(1,1,n,l,r);
                int mi=k.fi;
                if(mi==inf) continue;
                if(k.se>=2) {
                    ans+=k.se*(k.se-1)/2;
                    ans%=mod;
                }
                else {
                    int pos=seg.walk(1,1,n,l,r,mi);
                    seg.upd(1,1,n,pos,inf);
                    k=seg.query(1,1,n,l,r);
                    //cout << pos << "\n";
                    if(k.fi!=inf) ans+=k.se,ans%=mod;
                    seg.upd(1,1,n,pos,mi);
                    //cout << "a";
                }
            }
        }
        cout << ans << "\n";
    }
}