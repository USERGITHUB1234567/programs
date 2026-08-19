#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn=1000006;
int n,k;
long long a[maxn];
namespace soup1{
    void implement() {
        long long ans=0;
        int fm=(1<<(n-1));
        for(int mask=0; mask<fm; ++mask) {
            //cout << __builtin_popcount(mask) << '\n';
            if(__builtin_popcount(mask)!=k-1) continue;
            vector<long long>tmp;
            long long cur=0;
            for(int i=1; i<n; ++i) {
                int j=i-1;
                cur|=a[i];
                if(mask&(1<<j)) {tmp.push_back(cur),cur=0;}
            }
            cur|=a[n];
            tmp.push_back(cur);
            cur=tmp[0];for(int i=1; i<tmp.size(); ++i) cur&=tmp[i];
            ans=max(ans,cur);
        }
        cout << ans;
    }
}
namespace soup2{
    bool check_soup_condition() {
        for(int i=1; i<=n; ++i) if(a[i]>1) return false;
        return true;
    }
    int cnt[2];
    void implement() {
        for(int i=1; i<=n; ++i) ++cnt[a[i]];
        cout << (cnt[1]>=k?1:0);
    }
}
namespace soupf{
    long long f[102][102];
    void implement() {
        f[1][1]=a[1];
        for(int i=2; i<=n; ++i) {
            long long cur=a[i];
            for(int j=i-1; j>=1; --j) {
                for(int t=1; t<=j && t<k; ++t) {
                    f[i][t+1]=max(f[i][t+1],(cur&f[j][t]));
                }
                cur|=a[j];
            }
            f[i][1]=max(f[i][1],cur);
        }
        cout << f[n][k];
    }
}
int main(int argc, char** argv) {
    freopen("split.inp", "r", stdin);
    freopen("split.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    // soup1::implement();
    // cout << '\n';
    // soup2::implement();
    if(soup2::check_soup_condition()) soup2::implement();
    else if(n<=26)soup1::implement();
    //cout << '\n';
    else soupf::implement();
}
/*
7 3
2 1 4 3 2 2 5

6 2
1 0 0 1 2 2
*/