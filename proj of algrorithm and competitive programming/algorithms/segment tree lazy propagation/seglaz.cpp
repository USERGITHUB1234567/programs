#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int a[maxn];
struct segment_tree{
    long long st[maxn<<2],laz[maxn<<2];
    void build(int id, int l, int r) {
        if(l==r) {st[id]+=a[l];return;}
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    void down(int id, int l, int r) {
        long long t=laz[id];
        int m=(l+r)>>1;
        laz[id<<1]+=t;
        st[id<<1]+=t*(m-l+1);
        laz[id<<1|1]+=t;
        st[id<<1|1]+=t*(r-m);
        laz[id]=0;
    }
    void update(int id, int l, int r, int i, int j, int v) {
        if(l>j || r<i) return;
        if(l>=i && r<=j) {
            st[id]+=v*(r-l+1);
            laz[id]=v;
            return;
        }
        down(id,l,r);
        int m=(l+r)>>1;
        update(id<<1,l,m,i,j,v);
        update(id<<1|1,m+1,r,i,j,v);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    long long query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 0;
        down(id,l,r);
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return query(id<<1,l,m,i,j)+query(id<<1|1,m+1,r,i,j);
    }
}seg;

int main(){
    
}
