#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define foutput(name) freopen(name, "w", stdout);
#define finput(name) freopen(name,"r", stdin);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=100005,mod=1000000007;
long long fact[maxn],ifact[maxn];
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline ll maxill(ll a, ll b) {return (a>b?a:b);}
inline ll minill(ll a, ll b) {return (a<b?a:b);}
inline double maxid(double a, double b) {return (a>b?a:b);}
inline double minid(double a, double b) {return (a<b?a:b);}
inline ld maxild(ld a, ld b) {return (a>b?a:b);}
inline ld minild(ld a, ld b) {return (a<b?a:b);}
inline ll modexp(ll b, ll e, ll m) {
    ll res=1%m;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
void setupfactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod-2,mod);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int t;
long long l,r,k;
long long cnv1(string s) {
    long long res=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='0') res*=2;
        else res=1+res*2;
    }
    return res;
}
string cnv2(long long x) {
    string s="";
    while(x) {
        if(x&1) s='0'+s;
        else s='1'+s;
        x>>=1;
    }
    return s;
}
static long long calc(long long l, long long r) {
    int k=0;
    while(l<r) {
        l>>=1;
        r>>=1;
        ++k;
    }
    return l<<k;
}
void implement() {

}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    for(int i=1; i<=t; ++i) {
        cin >> l >> r >> k;
        long long m=calc(l,r),mask=(1LL<<k)-1;
        cout << ((m&mask)?"YES\n":"NO\n");
        /*string s="";
        for(int j=1; j<=k; ++j) s+='0';
        s='1'+s;
        string t=cnv2(l);
        bool kt=false;
        if(s.size()<t.size()) {
            while(s.size()<t.size()) s+='0';
        }
        for(int j=0; j<t.size()-k; ++j) {
            if(t[j]=='0') {
                kt=true;
                s[j]='1';
                break;
            }
        }
        if(!kt) {
            cout << "YES\n";
            continue;
        }
        long long n=cnv1(s);
        cout << (n>r?"YES\n":"NO\n");
        //string t=cnv2(l);
        //cout <<"a";*/
    }
    //string s=cnv2(1);
    /*string s="a";
    cout << s;*/
    return 0;
}