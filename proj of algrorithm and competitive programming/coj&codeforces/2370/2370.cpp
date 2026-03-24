#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int a[maxn],st[4*maxn],n,m;
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
int query(int id, int l, int r, int x, int y)
{
    if(r<x || st[id]<y) return -1;
    if(l==r) return l;
    int mid=(l+r)>>1;
    int lre=query(2*id,l,mid,x,y);
    if(lre!=-1) return lre;
    return query(2*id+1,mid+1,r,x,y);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    build(1,0,n-1);
    for(int i=1; i<=m; i++) {
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1) {
            upd(1,0,n-1,x,y);
        }
        else {
            cout << query(1,0,n-1,y,x) << "\n";
        }
    }
}
