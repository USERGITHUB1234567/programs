#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m;
namespace soup2{
    long long ans=0,fact[31];
    void implement() {
        fact[1]=1;for(int i=2; i<=30; ++i) fact[i]=fact[i-1]*i%mod;
        int fm=(1<<m);
        for(int mask=0; mask<fm; ++mask) {
            if(__builtin_popcount(mask)!=n) continue;
            vector<int>val;
            int tmp=-1;
            for(int i=0; i<m; ++i) {
                if(mask&(1<<i)) {val.push_back(i);}
                else if(tmp==-1) tmp=i;
            }
            sort(val.begin(),val.end());
            int mex=-1;
            for(int i=0; i<n; ++i) {

            }
        }
        cout << ans;
    }
}
namespace soupfull{
    const int maxn=1000006;
    long long fact[maxn],ifact[maxn];
    long long modexp(long long base, int e, int m) {
        long long res=1;
        while(e) {
            if(e&1) res=(res*base)%mod;
            base=(base*base)%mod;
            e>>=1;
        }
        return res;
    }
    long long ncr(int n, int k) {return fact[n]*ifact[n-k]%mod*ifact[k]%mod;}
    void implement() {
        fact[0]=1;fact[1]=1;
        for(int i=2; i<=n+1; ++i) fact[i]=fact[i-1]*i%mod;
        ifact[n+1]=modexp(fact[n+1],mod-2,mod);
        for(int i=n+1; i>=1; --i) {ifact[i-1]=ifact[i]*i%mod;}
        long long tmp=1,ans=0,t=m-n+1;
        for(int i=n; i>=1; --i) {
            ans=(ans+fact[i]*ncr(n+1,i+1)%mod*tmp%mod)%mod;
            tmp=tmp*t%mod;
            ++t;
        }
        cout << ans;
    }
}
int main(int argc, char** argv) {
    cin >> n >> m;
    soupfull::implement();
}