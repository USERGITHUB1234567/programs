#include "secret.h"
const int maxn=1003;
int dst[12][maxn],a[maxn],n;
void build(int lev, int l, int r) {
    if(l==r) return;
    int mid=(l+r)>>1;
    dst[lev][mid]=a[mid];dst[lev][mid+1]=a[mid+1];
    for(int i=mid-1; i>=l; --i) {
        dst[lev][i]=Secret(a[i],dst[lev][i+1]);
    }
    for(int i=mid+2; i<=r; ++i) {
        dst[lev][i]=Secret(dst[lev][i-1],a[i]);
    }
    build(lev+1,l,mid);
    build(lev+1,mid+1,r);
}
void Init(int N, int A[]) {
    n=N;
    for(int i=0; i<n; ++i) a[i]=A[i];
    build(0,0,n-1);
}
int get(int lev, int l, int r, int i, int j) {
    if(l==r) return a[l];
    int mid=(l+r)>>1;
    if(i<=mid && j>mid) return Secret(dst[lev][i],dst[lev][j]);
    if(j<=mid) return get(lev+1,l,mid,i,j);
    else return get(lev+1,mid+1,r,i,j);
}
int Query(int l, int r) {
    return get(0,0,n-1,l,r);
}