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
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=1000006,mod1=1000000007,mod2=1000000003;
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
inline ll log(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
void setupfactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod1;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod1-2,mod1);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%1; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod1*ifact[k]%mod1);}
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,t;
string s;
char q;
namespace souptrau {
    inline bool check(const string &m) {
        for(int i=0; i<m.size()/2; ++i) if(m[i]!=m[m.size()-1-i]) return false;
        return true;
    }
    inline int cal(const string &m) {
        int res=0;
        for(int i=0; i<(int)m.size(); ++i) {
            for(int j=i; j<(int)m.size(); ++j) {
                if(check(m.substr(i, j-i+1))) res=max(res,j-i+1);
            }
        }
        return res;
    }
    void solve() {
        for(int i=1; i<=n; ++i) {
            if(!(cin >> t)) return;
            if(t==1) {
                cin >> q;
                s.push_back(q);
            } else {
                if(!s.empty()) s.pop_back();
            }
            cout << cal(s) << '\n';
        }
    }
}
namespace soupupg {
    vector<int>st;
    inline bool check(const string &m) {
        for(int i=0; i<m.size()/2; ++i) if(m[i]!=m[m.size()-1-i]) return false;
        return true;
    }
    void solve() {
        st.pb(0);
        for(int k=1; k<=n; ++k) {
            cin >> t;
            if(t==1) {
                cin >> q;s+=q;
                int l=0;
                for(int i=0; i<s.size(); ++i) {
                    if(check(s.substr(i,s.size()-i+1))) {l=max(l,(int)s.size()-i+1);break;}
                }
                st.pb(max(st.back(),l));
                cout << st.back()-1 << '\n';
            }else {
                if(!s.empty()) s.pop_back();
                st.pop_back();
                cout << st.back()-1 << '\n';
            }
        }
    }
}
namespace soupfull {
    const ll base=3;
    ll a[maxn],cur=0,p[maxn],ip[maxn],h[maxn],ih[maxn];
    int c;
    vector<int>st;
    inline bool check(int l, int r) {
        ll h1=((h[r]-h[l-1]+mod1)%mod1)*ip[l]%mod1,h2=((ih[r]-ih[l-1]+mod1)%mod1)*p[r]%mod1;
        return h1==h2;
    }
    void solve() {
        p[0]=ip[0]=1;
        ip[1]=modexp(base,mod1-2,mod1);
        h[0]=ih[0]=0;
        for(int i=1; i<=n; ++i) {p[i]=p[i-1]*base%mod1;ip[i]=ip[i-1]*ip[1]%mod1;}
        while(n--) {
            cin >> t;
            if(t==1) {
                cin >> c;++c;
                ++cur;
                h[cur]=(h[cur-1]+c*p[cur])%mod1;
                ih[cur]=(ih[cur-1]+c*ip[cur])%mod1;
                
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("3192")
    if(!(cin >> n)) return 0;
    soupupg::solve();
    return 0;
}
/*
code full
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define FOR(i,a,b) for( int i = a ; i <= b ; i++ )
#define REP(i,a,b) for( int i = a ; i >= b ; i-- )
const int maxn = 1000009;
int n ;
int a[maxn];
int cur = 0;
vector<int> status;
const ll base = 3;
const ll mod = 1e9+7;
ll p[maxn] , inv_p[maxn];
ll h[maxn] , inv_h[maxn];


//bool chec( int l , int r ){
////    FOR(i,l,(r+1)/2)
////        if( a[i] != a[r-i+1] ) return 0;
//    while(l<r){
//        if( a[l] != a[r] ) return 0;
//        l++;
//        r--;
//    }
//    return 1;
//}

bool chec( int l , int r ){
    ll hash1 = ( (h[r] - h[l-1] + mod)%mod ) * inv_p[l] % mod;
    ll hash2 = ( ( inv_h[r] - inv_h[l-1] + mod )%mod ) * p[r] % mod;
    if( hash1 == hash2 ) return 1;
    return 0;
}

ll powmod( ll a , int n ){
    ll res = 1;
    while( n ){
        if( n % 2 == 1 )
            res = (res*a)%mod;
        a = (a*a)%mod;
        n = n/2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen( "name.inp" , "r" , stdin );
//    freopen( "name.out" , "w" , stdout );
    cin >> n;
    p[0] = 1;
    FOR(i,1,n)
        p[i] = (p[i-1]*base)%mod;
    inv_p[0] = 1;
    inv_p[1] = powmod(base,mod-2);
    FOR(i,2,n)
        inv_p[i] = ( inv_p[i-1] * inv_p[1] ) % mod;
    status.pb(0);
    h[0] = 0;
    inv_h[0] = 0;
    while(n--){
        int type;
        cin >> type;
        if( type == 1 ){
            int v;
            cin >> v;
            v++;
            cur++;
            h[cur] = ( h[cur-1] + v*p[cur] ) % mod;
            inv_h[cur] = ( inv_h[cur-1] + v*inv_p[cur] ) % mod;
            a[cur] = v;
            int l1 = status.back();
            int l2 = status.back();
            if( cur-(l1+1)+1 >= 1 && chec( cur-(l1+1)+1 , cur) ) l1 = l1+1;
            if( cur-(l2+2)+1 >= 1 && chec( cur-(l2+2)+1 , cur) ) l2 = l2+2;
            status.pb( max(l1,l2) );
//            cout << l << " ";
            cout << status.back() << '\n';
        }
        else{
            cur--;
            status.pop_back();
            cout << status.back() << '\n';
        }




    }


}
*/