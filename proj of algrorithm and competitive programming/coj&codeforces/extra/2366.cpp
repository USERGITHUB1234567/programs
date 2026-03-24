#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5+7;
int a[N];
int st[4 * N];
int inf=1e9+7;
void build(int id, int l, int r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}
void update(int id, int l, int r, int i, int val)
{
    //if(l > i or r < i) return inf;
    if(l==r) {
        st[id]=val;
        return;
    }
    int mid = (l + r) >> 1;
    if(i <= mid){
        update(2 * id,l, mid, i, val);
    }
    else update(2 * id + 1, mid + 1, r, i, val);
    st[id] = min(st[2 * id], st[2 * id +1]);
}
int query(int id, int l, int r, int u, int v)
{
    if(u > r or v < l) {
        return inf;
    }
    if(u <= l and v >= r) {
        return st[id];
    }
    int mid = (l + r) >> 1;
    long long q1 = query(2 * id, l, mid, u, v);
    long long q2 = query(2 * id + 1, mid + 1, r, u , v);
    return min(q1, q2);
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    while(m--) {
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) update(1, 1, n, x, y);
        else cout <<  query(1, 1, n, x, y) << "\n";
    }
}
