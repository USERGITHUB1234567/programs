#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int l[100005],n,ans[100005],st[600000];
void upd(int id, int l, int r, int i, int v)
{
    if(l==r) {
        st[id]=v;
        return;
    }
    int mid=(l+r)>>1;
    if(i<=mid) upd(2*id+1,l,mid,i,v);
    else upd(2*id+2,mid+1,r,i,v);
    st[id]=st[id*2+1]+st[2*id+2];
}
int query(int id, int l, int r, int u, int v)
{
    if(u>r || v<l) return 0;
    if(l>=u && r<=v) return st[id];
    int mid=(l+r)>>1;
    return query(2*id+1,l,mid,u,v)+query(2*id+2,mid+1,r,u,v);
}
int main()
{
    cin >> n;
    for(int i=1; i<=2*n; i++) {
        int a;
        cin >> a;
        if(l[a]==0) {
            l[a]=i;
            upd(1,1,2*n,l[a],1);
            //cout << i << " " << a << "\n";
        }
        else {
            upd(1,1,2*n,l[a],0);
            ans[a]=query(1,1,2*n,l[a]+1,i-1);
            //upd(1,1,2*n,i,1);
            //if(a==1) cout << query(1,1,2*n,l[a],i);
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i];
        if(i<n)  cout << " ";
    }
}
