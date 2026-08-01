#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int st[4*maxn];
int a[maxn];
int n,m;
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
void upd(int id, int l, int r, int k)
{
    if(l==r) {
        st[id]=1-st[id];
        a[l]=1-a[l];
        return;
    }
    int mid=(l+r)>>1;
    if(k<=mid) upd(2*id,l,mid,k);
    else upd(2*id+1,mid+1,r,k);
    st[id]=st[2*id]+st[2*id+1];
}
int query(int id, int l, int r, int k)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(st[2*id]>=k+1) return query(2*id,l,mid,k);
    else return query(2*id+1,mid+1,r,k-st[2*id]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    build(1,0,n-1);
    for(int i=1; i<=m; i++) {
        int t,k;
        cin >> t >> k;
        if(t==1) {
            upd(1,0,n-1,k);
        }
        else {
            cout << query(1,0,n-1,k) << "\n";
        }
    }
}
