#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,d,a[maxn],x[maxn],y[maxn],s[maxn],st_min[maxn][20],st_max[maxn][20];
int main(int argc, char** argv) {
    cin >> n >> d;for(int i=1; i<=n; ++i) {
        cin >> a[i];s[i]=s[i-1]+(a[i]>=1);x[i]=i-a[i],y[i]=a[i]-s[i];
        st_min[i][0]=x[i];
        st_max[i][0]=y[i];
    }
    long long ans=0;
    int logn=32-__builtin_clz(n);
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) {
            if(i+(1<<j)-1>n) break;
            int nxt=i+(1<<(j-1));
            st_min[i][j]=min(st_min[i][j-1],st_min[nxt][j-1]);
            st_max[i][j]=max(st_max[i][j-1],st_max[nxt][j-1]);
        }
    }
    auto query_min=[&](int l, int r) {
        int lg=31-__builtin_clz(r-l+1);
        int t=(1<<lg);
        return min(st_min[l][lg],st_min[r-t+1][lg]);
    };
    auto query_max=[&](int l, int r) {
        int lg=31-__builtin_clz(r-l+1);
        int t=(1<<lg);
        return max(st_max[l][lg],st_max[r-t+1][lg]);
    };
    for(int i=1; i<=n; ++i) {
        if(!a[i]) {
            int r=n,l=i;
            while(l<r) {
                int mid=(l+r+1)>>1;
                if(query_max(i,mid)<=d-s[mid] && query_min(i,mid)>=i) l=mid;
                else r=mid-1;
            }
            ans+=l-i+1;
        }
    }
    cout << ans;
}
