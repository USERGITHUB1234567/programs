#include <bits/stdc++.h>
using namespace std;
const int mod1=1000000009,mod2=1000000003,maxn=100005,base=311;
string s;
int n,pre[maxn];
pair<long long,long long>hashing[maxn],p[maxn],revhash[maxn];
pair<long long,long long>get_hash1(int l, int r) {
    long long h1=(hashing[r].first-hashing[l-1].first*p[r-l+1].first+mod1*mod1)%mod1;
    long long h2=(hashing[r].second-hashing[l-1].second*p[r-l+1].second+mod2*mod2)%mod2;
    return {h1,h2};
}
pair<long long,long long>get_hash2(int l, int r) {
    long long h1=(revhash[l].first-revhash[r+1].first*p[r-l+1].first+mod1*mod1)%mod1;
    long long h2=(revhash[l].second-revhash[r+1].second*p[r-l+1].second+mod2*mod2)%mod2;
    return {h1,h2};
}
bool check(int l, int r) {
    return get_hash1(l,r)==get_hash2(l,r);
}
// int query(int t) {
//     int cnt=0;
//     for(int i=1; i<=i+t+1; ++i) {
//         int mid=(2*i+t-1)>>1,r=i+t-1;
//         if(pre[r]-pre[i-1]!=0 && pre[r]-pre[i-1]!=t && check(i,mid) && check(mid+1,r)) ++cnt;
//     }
//     return cnt;
// }
int main(int argc, char** argv) {
    cin >> s;
    n=s.size();
    p[0].first=p[0].second=1;
    for(int i=1; i<=n; ++i) {
        int c=s[i-1]-'a';
        pre[i]=pre[i-1]+c;
        p[i].first=p[i-1].first*base%mod1;
        p[i].second=p[i-1].second*base%mod2;
        hashing[i].first=(hashing[i-1].first*base+c)%mod1;
        hashing[i].second=(hashing[i-1].second*base+c)%mod2;
    }
    for(int i=n; i>=1; --i) {
        int c=s[i-1]-'a';
        revhash[i].first=(revhash[i+1].first*base+c)%mod1;
        revhash[i].second=(revhash[i+1].second*base+c)%mod2;
    }
    int cnt=0,ans=-1;
    for(int k=(n>>1); k>=1; --k) {
        int sz=(k<<1);
        cnt=0;
        for(int i=1; i<=n-sz+1; ++i) {
            int mid=(i+k),r=i+sz-1;
            if(check(i,mid-1) && check(mid,r) && pre[r]-pre[i-1]!=0 && pre[r]-pre[i-1]!=sz) ++cnt;
        }
        if(cnt) {
            ans=sz;
            break;
        }
    }
    if(ans==-1) cout << ans;
    else cout << ans << ' ' << cnt;
}
