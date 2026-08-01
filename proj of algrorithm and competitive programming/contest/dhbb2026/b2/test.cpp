/**/ 
#pragma GCC optimize("O3") 
#include <bits/stdc++.h> 
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout); 
#define all(x) x.begin(), x.end() 
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end()); 
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i)) 
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i)) 
#define eb emplace_back 
#define fi first 
#define se second 
#define pb push_back 
using namespace std; 
using namespace std::chrono; 

static const int maxd=1003; 
typedef short bignum[maxd]; 
typedef long long ll; 
typedef long double ld; 

// Tăng maxn lên 100005 để tránh tràn mảng nếu testcase Subtask 5 có N lớn
const int maxn=100005, mod=1000000007, maxb=320; 

namespace utilities{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(b!=0) {long long c=a%b;a=b;b=c;} return a; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
    inline int maxi(int a, int b) {return (a>b?a:b);} 
    inline int mini(int a, int b) {return (a<b?a:b);} 
    inline ll maxill(ll a, ll b) {return (a>b?a:b);} 
    inline ll minill(ll a, ll b) {return (a<b?a:b);} 
    inline double maxid(double a, double b) {return (a>b?a:b);} 
    inline double minid(double a, double b) {return (a<b?a:b);} 
    inline ld maxild(ld a, ld b) {return (a>b?a:b);} 
    inline ld minild(ld a, ld b) {return (a<b?a:b);} 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=modexp(fact[tc],mod-2,mod); for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
} 
using namespace utilities; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 

int t, n;
long long v[maxn];

namespace soup1{
    vector<int>status;
    map<vector<int>,pair<pair<int,int>,vector<int>>>trace;
    int f(vector<int>&v) {return count(all(v),0);}
    vector<int> bfs(vector<int>&s) {
        queue<vector<int>>q;
        vector<int>res=s;
        int mx=f(s);
        q.push(s);
        int cnt=0;
        while(!q.empty() && cnt<=10000) {
            auto u=q.front();q.pop();
            ++cnt;
            for(int i=0; i<u.size(); ++i) {
                for(int j=0; j<u.size(); ++j) {
                    if(i==j) continue;
                    if(u[i]>=u[j] && u[i]!=0) {
                        vector<int>v=u;
                        v[i]-=v[j];v[j]<<=1;
                            if(trace[v].se.size()==0) {
                            trace[v]={{i,j},u};
                            q.push(v);
                        }
                        if(f(v)>mx) {
                            mx=f(v);
                            res=v;
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<pair<int,int>>traverse(vector<int>&s) {
        vector<pair<int,int>>res;
        while(s!=status) {
            res.pb(trace[s].fi);
            s=trace[s].se;
        }
        reverse(all(res));
        return res;
    }
    void solve() {
        while(t--) {
            status.clear();
            trace.clear();
            cin >> n;for(int i=1; i<=n; ++i) {cin >> v[i];status.pb(v[i]);}
            vector<int>ans=bfs(status);
            vector<pair<int,int>>res=traverse(ans);
            cout << res.size() << '\n';
            for(auto[u,v]:res) cout << u+1 << ' ' << v+1 << '\n';
        }
    }
}

namespace soupfull{
    vector<pair<int,int>> res;
    
    inline bool check(long long x) {
        if(x <= 0) return false;
        return (x & (x - 1)) == 0;
    }
    
    void solve() {
        while(t--) {
            cin >> n;
            res.clear();
            
            multiset<pair<long long, int>> ms;
            long long tv = 0, g = 0;
            
            for(int i = 1; i <= n; ++i) {
                long long x; 
                cin >> x;
                if(x > 0) {
                    ms.insert({x, i});
                }
                tv += x;
                g = __uiagcd(g, x);
            }
            
            // Pha 1: Rút gọn số bình còn <= 2 bằng Euclidean Division giả lập
            while(ms.size() >= 3) {
                auto itA = ms.begin();
                auto a_pair = *itA; ms.erase(itA);
                
                auto itB = ms.begin();
                auto b_pair = *itB; ms.erase(itB);
                
                auto itC = ms.begin();
                auto c_pair = *itC; ms.erase(itC);
                
                long long a = a_pair.fi; int id1 = a_pair.se;
                long long b = b_pair.fi; int id2 = b_pair.se;
                long long c = c_pair.fi; int id3 = c_pair.se;
                
                long long q = b / a;
                int m = 63 - __builtin_clzll((unsigned long long)q);
                long long target = a;
                
                for(int i = 0; i <= m; ++i) {
                    if((q >> i) & 1) {
                        b -= target;
                        a += target;
                        res.pb({id2, id1});
                    }
                    else {
                        c -= target;
                        a += target;
                        res.pb({id3, id1});
                    }
                    target <<= 1;
                }
                
                if(a > 0) ms.insert({a, id1});
                if(b > 0) ms.insert({b, id2});
                if(c > 0) ms.insert({c, id3});
            }
            
            // Pha 2: Gom 2 bình cuối nếu thoả mãn bất biến
            if(tv > 0 && g > 0) {
                long long odd_g = g;
                while(odd_g > 0 && odd_g % 2 == 0) odd_g /= 2;
                
                if(tv % odd_g == 0 && check(tv / odd_g)) {
                    while(ms.size() >= 2) {
                        auto itA = ms.begin();
                        auto a_pair = *itA; ms.erase(itA);
                        
                        auto itB = ms.begin();
                        auto b_pair = *itB; ms.erase(itB);
                        
                        long long a = a_pair.fi; int id1 = a_pair.se;
                        long long b = b_pair.fi; int id2 = b_pair.se;
                        
                        res.pb({id2, id1});
                        b -= a;
                        a += a;
                        
                        if(a > 0) ms.insert({a, id1});
                        if(b > 0) ms.insert({b, id2});
                    }
                }
            }
            
            cout << res.size() << '\n';
            for(auto p : res) cout << p.fi << ' ' << p.se << '\n';
        }
    }
}

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    if (cin >> t) {
        soupfull::solve();
    }
    return 0; 
} 
/**/