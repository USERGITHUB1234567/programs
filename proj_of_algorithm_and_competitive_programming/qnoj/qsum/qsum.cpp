#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=50004;
int st[4*maxn],laz[4*maxn],a[maxn],n,q;
void build(int id, int l, int r)
{
    if(l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
void down(int id, int l, int r)
{
    if(laz[id]!=0) {
        if(l==r) {
            laz[id]=0;
            return;
        }
        int mid=(l+r)>>1;
        st[2*id]+=laz[id]*(mid-l+1);
        laz[2*id]+=laz[id];
        st[2*id+1]+=laz[id]*(r-mid);
        laz[2*id+1]+=laz[id];
        laz[id]=0;
    }
}
void upd(int id, int l, int r, int u, int v, int w)
{
    down(id,l,r);
    if(r<u || l>v) return;
    if(u<=l && v>=r) {
        st[id]+=w*(r-l+1);
        laz[id]+=w;
        return;
    }
    int mid=(l+r)>>1;
    upd(2*id,l,mid,u,v,w);
    upd(2*id+1,mid+1,r,u,v,w);
    st[id]=st[2*id]+st[2*id+1];
}
int get(int id, int l, int r, int u, int v)
{
    down(id,l,r);
    if(r<u || l>v) return 0;
    if(l>=u && r<=v) return st[id];
    int mid=(l+r)>>1;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    while(q--) {
        char c;
        cin >> c;
        if(c=='+') {
            int i,j,v;
            cin >> i >> j >> v;
            upd(1,1,n,i,j,v);
        }
        else {
            int u,v;
            cin >> u >> v;
            cout << get(1,1,n,u,v) << "\n";
        }
    }
}
