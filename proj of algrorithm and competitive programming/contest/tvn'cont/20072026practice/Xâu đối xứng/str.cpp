/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
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
const int maxn=5003;
const long long mod1=1000000007,mod2=1000000003,maxb=320,base=31; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
string s;
int n;
pair<long long, long long> hash1[maxn], hash2[maxn];
pair<long long, long long> power[maxn];
pair<long long, long long> get_hash1(int l, int r) {
    long long h1=(hash1[r].fi-hash1[l-1].fi*power[r-l+1].fi%mod1+mod1)%mod1;
    long long h2=(hash1[r].se-hash1[l-1].se*power[r-l+1].se%mod2+mod2)%mod2;
    return {h1,h2};
}
pair<long long, long long> get_hash2(int l, int r) {
    long long h1=(hash2[l].fi-hash2[r+1].fi*power[r-l+1].fi%mod1+mod1)%mod1;
    long long h2=(hash2[l].se-hash2[r+1].se*power[r-l+1].se%mod2+mod2)%mod2;
    return {h1,h2};
}
// struct fenwick_tree{
//     int bit[maxn];
//     int sum(int i) {
//         int res=0;
//         while(i) {
//             res+=bit[i];
//             i-=i&-i;
//         }
//         return res;
//     }
//     void update(int i, int v) {
//         while(i<=n) {
//             bit[i]+=v;
//             i+=i&-i;
//         }
//     }
// }fen;
int bit[maxn];
void update(int i, int v) {
    while(i<=n) {
        bit[i]+=v;
        i+=i&-i;
    }
};
int query(int i) {
    int res=0;
    while(i>0) {
        res+=bit[i];
        i-=i&-i;
    }
    return res;
};
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> s;
    n=s.size();
    power[0] = {1, 1};
    for(int i=1; i<=n; ++i) {
        power[i].fi=power[i-1].fi*base%mod1;
        power[i].se=power[i-1].se*base%mod2;
    }
    for(int i=1; i<=n; ++i) {
        auto[a,b]=hash1[i-1];
        long long h1,h2;
        h1=(a*base+s[i-1]-'a')%mod1;
        h2=(b*base+s[i-1]-'a')%mod2;
        hash1[i]={h1,h2};
    }
    for(int i=n; i>=1; --i) {
        auto[a,b]=hash2[i+1];
        long long h1,h2;
        h1=(a*base+s[i-1]-'a')%mod1;
        h2=(b*base+s[i-1]-'a')%mod2;
        hash2[i]={h1,h2};
    }
    vector<vector<int>>ends(n+2);
    for(int i=1; i<=n; ++i) {
        for(int j=i; j<=n; ++j) {
            if(get_hash1(i,j)==get_hash2(i,j)) {
                ends[j].pb(i);
            }
        }
    }
    int q; cin >> q;
    vector<array<int,3>>queries(q);
    for(int i=0; i<q; ++i) {
        int l,r; cin >> l >> r;
        queries[i]={r,l,i};
    }
    sort(queries.begin(), queries.end());
    vector<long long>ans(q);
    int qi=0;
    for(int r=1; r<=n; ++r) {
        for(int u:ends[r]) {
            update(u,1);
        }
        while(qi<q && queries[qi][0]==r) {
            int l=queries[qi][1];
            int id=queries[qi][2];
            ans[id]=query(r)-query(l-1);
            ++qi;
        }
    }
    for(int i=0; i<q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0; 

} 
/**/