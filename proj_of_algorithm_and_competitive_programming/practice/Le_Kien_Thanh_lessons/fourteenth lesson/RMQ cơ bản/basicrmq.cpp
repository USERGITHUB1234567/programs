#include "secret.h"
#include <algorithm>
const int maxn=1024;
int dst[12][maxn],a[maxn],n;
void Init(int N, int A[]) {
    n=N;
    for(int i=0; i<n; ++i) a[i]=A[i];
    for(int h=0; h<10; ++h) {
        int half=(1<<h),block=(half<<1);
        for(int i=0; i<n; i+=block) {
            int mid=i+half-1;
            if(mid>=n-1) continue;
            dst[h][mid]=a[mid],dst[h][mid+1]=a[mid+1];
            for(int j=mid-1; j>=i; --j) dst[h][j]=Secret(a[j],dst[h][j+1]);
            int e=std::min(i+block-1,n-1);
            for(int j=mid+2; j<=e; ++j) dst[h][j]=Secret(dst[h][j-1],a[j]);
        }
    }
}
int Query(int l, int r) {
    int h=31-__builtin_clz(l^r);
    if(l==r) return a[l];
    return Secret(dst[h][l],dst[h][r]);
}