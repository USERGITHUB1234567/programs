#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,q;
long long a[maxn],b[maxn],dif[maxn],ans[maxn];
vector<pair<long long,int>>query;
int main(int argc, char** argv) {
    freopen("clocks.inp", "r", stdin);
    freopen("clocks.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i] >> b[i];
    cin >> q;
    query.reserve(q);
    for(int i=1; i<=q; ++i) {
        int x;cin >> x;
        query.push_back({x,i});
    }
    sort(query.begin(),query.end());
    for(int i=1; i<=n; ++i) {
        long long div=a[i]/m,mod=a[i]%m;
        dif[0]+=div;
        int p=lower_bound(query.begin(),query.end(),make_pair(b[i],0))-query.begin();
        ++dif[p];
        p=upper_bound(query.begin(),query.end(),make_pair(b[i]+mod,0))-query.begin();
        if(b[i]+mod>=m) {
            int t=(b[i]+mod)%m;
            ++dif[0];
            p=upper_bound(query.begin(),query.end(),make_pair(t,0))-query.begin();
            --dif[p];
        }else --dif[p];
    }
    long long cur=0;
    for(int i=0; i<q; ++i) {
        cur+=dif[i];
        ans[query[i].second]=cur;
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
}