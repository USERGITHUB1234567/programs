#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=200005;
int n,q,a[maxn],st[4*maxn],s1[maxn][maxn];
int __gcd(int a,int b) {
    while(b) {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
void build(int id, int l, int r) {
    if(l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=__gcd(st[2*id],st[2*id+1]);
}
int query(int id, int l, int r, int u, int v, int x) {
    if(l<u || r>v) return 0;
    if(u<=l && v>=r) {
        if(st[id]>=x) {
            int m=(l-r+1);
            return m*(m-1)/2;
        }
    }
    int mid=(l+r)>>1;
    int q1=query(2*id,l,mid,u,v,x),q2=query(2*id+1,mid+1,r,u,v,x);
    return q1+q2;
}
void soup1() {
    for(int l=1; l<=n; l++) {
        int gcd=a[l];
        for(int r=l; r<=n; r++) {
            gcd=__gcd(gcd,a[r]);
            s1[l][r]=gcd;
        }
    }
    while(q--) {
        int l,r,x;
        cin >> l >> r >> x;
        int kq=0;
        for(int i=l; i<=r; i++) {
            for(int j=i; j<=r; j++) {
                if(s1[i][j]>=x) kq++;
            }
        }
        cout << kq << "\n";
    }
}
void soup2() {
    int kq=0;
    for(int l=1; l<=n; l++) {
        int gcd=a[l];
        for(int r=l; r<=n; r++) {
            gcd=__gcd(gcd,a[r]);
            s1[l][r]=gcd;
        }
    }
    while(q--) {
        int l,r,x;
        cin >> l >> r >> x;
        int i=l,j=l;
        while(j<r) {
            //int gcd=s1[i][j];
            while(s1[i][j]<x && i<j) i++;
            int seq=(j-i+1);
            if(s1[i][j]>=x) kq+=seq*(seq-1)/2;
            j++;
        }
        cout << kq << "\n";
    }
}
void soup3() {
    build(1,1,n);
    while(q--) {
        int l,r,x;
        cin >> l >> r >> x;
        cout << query(1,1,n,l,r,x) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("gcd");
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    soup1();
}