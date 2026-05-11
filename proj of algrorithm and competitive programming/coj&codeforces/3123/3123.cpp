#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define int long long
using namespace std;
const int maxn=300005;
int n,d;
long long a[maxn],kq=0,mi=LLONG_MAX,ma=0;
set<long long>st;
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> d;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=d+2; i<=n; i++) {
        int j=i-d-1;
        mi=min(mi,a[j]);
        ma=max(ma,a[j]);
        long long t1=a[i]*mi,t2=a[i]*ma;
        long long m=max(t1,t2);
        if(m>0) kq=max(kq,m);
    }
    cout << kq;
}