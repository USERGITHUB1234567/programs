#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int n,m,a[maxn];
int st[maxn*4];
void build(int id, int l, int r)
{
    if(l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=max(st[2*id],st[2*id+1]);
}
void upd(int id, int l, int r, int i, int v)
{
    if(l==r) {
        st[id]=v;
        return;
    }
    int mid=(l+r)>>1;
    if(i<=mid) upd(2*id,l,mid,i,v);
    else upd(2*id+1,mid+1,r,i,v);
    st[id]=max(st[2*id],st[2*id+1]);
}
int query(int id, int l, int r, int x)
{
    if(st[id]<x) return 0;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(st[2*id]>=x) {
        return query(2*id,l,mid,x);
    }
    else return query(2*id+1,mid+1,r,x);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    //build(1,1,n);
    build(1,1,n);
    for(int i=1; i<=m; i++) {
        int r;
        cin >> r;
        int vt=query(1,1,n,r);
        cout << vt;
        if(vt!=0) {
            a[vt]-=r;
            upd(1,1,n,vt,a[vt]);
        }
        if(i<m) cout << " ";
    }
    return 0;
}
