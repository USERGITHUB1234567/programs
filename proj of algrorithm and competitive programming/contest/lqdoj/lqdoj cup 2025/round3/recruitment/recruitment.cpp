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
const int maxn=9000006,mod=1000000000+19972207;
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
long long akn(ll k, ll n) {
    
}
int souptrau(vector<int>&a, int k) {
    //bool kt=true;
    int cur,d,kq=0;
    do{
        d=k;
        cur=a[0];
        if(cur==1) continue;
        bool ck=false;
        //for(int i=0; i<a.size(); ++i) cout << a[i] << " ";
        //cout << "\n";
        for(int i=1; i<a.size(); ++i) {
            if(a[i]<cur) {
                cur=a[i];
                d=k;
            }
            else --d;
            if(a[i]==1) break;
            if(d==0) {
                kq=(kq+1)%mod;
                ck=true;
                break;
            }
        }
        //cout << ck << "\n";
        /*if(ck) {
            for(int i:a) cout << i << " ";
            cout << "\n";
        }*/
    }while(next_permutation(all(a)));
    //return false;
    return kq;
}
long long com[1003][1003];
void factor() {
    fact[0]=1;
    for(int i=1; i<=maxn; ++i) {
        fact[i]=fact[i-1]*i%mod;
    }
    for(int i=0; i<1003; ++i) com[i][0]=com[i][i]=1;
    for(int i=1; i<1003; ++i) {
        for(int j=1; j<=i; ++j) {
            com[i][j]=(com[i-1][j]+com[i-1][j-1])%mod;
            //cout << com[i][j] << ' ';
        }
        //cout << "\n";
    }
    //cout << com[3][2];
}
void soupfull(ll n, ll k) {
    long long kq=0;
    for(ll i=k+2; i<=n; ++i) {
        long long cur=com[n-k][i-k]*com[n-i+k][k]%mod*fact[n-i]%mod;
        kq=(kq+cur)%mod;
    }
    cout << kq << "\n";
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("recruitment")
    cin >> t;
    factor();
    while (t--) {
        int n,k;
        cin >> n >> k;
        if(n<=10) {
            vector<int>a;
            int kq=0;
            for(int i=1; i<=n; ++i) {
                a.pb(i);
            }
            int fm=1<<n;
            for(int mask=1; mask<fm; ++mask) {
                vector<int>b;
                if(!(mask&1)) continue;
                for(int i=0; i<n; ++i) {
                    if(mask&(1<<i)) b.pb(a[i]);
                }
                //for(int i:b) cout << i << " ";
                //cout << "\n";
                //if(b.empty()) continue;
                kq+=souptrau(b,k);
            }
            cout << kq << "\n";
                //kq+=souptrau(a,k); 
        }
        /*else {
            soupfull(n,k);
        }*/
       //cout << "\n";
       //soupfull(n,k);
    }
    return 0;
}