#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,x;
long long s[maxn],f[maxn];
namespace soup1{
    void implement() {
        int fm=(1<<(n-1));
        long long ans=1e18;
        for(int mask=0; mask<fm; ++mask) {
            long long cur=x,tmp=0;
            for(int bit=mask; bit; bit&=(bit-1)) {
                int i=__builtin_ctz(bit);
                tmp+=cur*s[i+1];
                cur=f[i+1];
            }
            tmp+=cur*s[n];
            ans=min(ans,tmp);
        }
        cout << ans;
    }
}
struct convex_hull_trick{
    vector<pair<long long,long long>>hull;
    bool bad(pair<long long, long long>l1, pair<long long, long long>l2, pair<long long,long long>l3) {
        double x12=(double)(l2.second-l1.second)/(l1.first-l2.first);
        double x23=(double)(l3.second-l2.second)/(l2.first-l3.first);
        return x12>=x23;
    }
    void add(pair<long long,long long>l) {
        if(!hull.empty() && hull.back().first==l.first && hull.back().second<=l.second) return;
        while(hull.size()>1 && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
        hull.push_back(l);
    }
    long long query(long long x) {
        int l=0,r=hull.size()-1;
        if(hull.size()==1) return hull.back().first*x+hull.back().second;
        if(hull.size()==2) {
            long long t1=hull[0].first*x+hull[0].second;
            long long t2=hull[1].first*x+hull[1].second;
            return min(t1,t2);
        }
        while(l<r) {
            int mid=(l+r)>>1;
            if(hull[mid].first*x+hull[mid].second<=hull[mid+1].first*x+hull[mid+1].second) r=mid;
            else l=mid+1;
        }
        return hull[l].first*x+hull[l].second;
    }
};
namespace soup2{
    long long dp[maxn];
    void implement() {
        for(int i=1; i<=n; ++i) {
            dp[i]=s[i]*x;
            for(int j=i-1; j>=1; --j) {
                dp[i]=min(dp[i],dp[j]+f[j]*s[i]);
            }
        }
        //long long ans=s[n]*x;
        cout << dp[n];
    }
}
namespace soupfull{
    long long dp[maxn];
    void implement() {
        //long long ans=x*s[n];
        dp[1]=s[1]*x;
        convex_hull_trick cht;
        cht.add({f[1],dp[1]});
        for(int i=2; i<=n; ++i) {
            //ans=min(ans,)
            long long tmp=s[i]*x,query=cht.query(s[i]);
            dp[i]=min(tmp,query);
            cht.add({f[i],dp[i]});
        }
        cout << dp[n];
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> s[i];
    for(int i=1; i<=n; ++i) cin >> f[i];
    //soup1::implement();
    //cout << '\n';
    if(n<=2000)soup2::implement();
    //cout << '\n';
    else soupfull::implement();
    //cout << '\n';
    //soupfull::implement();
}
