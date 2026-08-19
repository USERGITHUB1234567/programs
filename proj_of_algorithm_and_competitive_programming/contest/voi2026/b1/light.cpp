/**/
#pragma GCC optimize("O3,Ofast")
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
const int maxn=100005,mod=1000000007,maxb=320;
namespace utilities{
    long long fact[maxn],ifact[maxn];
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; }
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
    inline int lomuto_partition(vector<int>&a, int l, int r) {int pivot=a[r],i=l-1;for(int j=l; j<r; ++j) {if(a[j]<=pivot) {++i;swap(a[i],a[j]);}}swap(a[r],a[i+1]);return i+1;}
    inline int hoare_partition(vector<int>&a, int l, int r) {int pivot=a[l],i=l,j=r;bool partition=true;while(partition) {while(a[i]<pivot) ++i;while(a[j]>pivot) --j;if(i<j) {swap(a[i],a[j]);++i,--j;}else partition=false;}return j;}
    inline void quicksort_lomuto(vector<int>&a, int l, int r) {if(l>=r) return;int p=lomuto_partition(a,l,r);quicksort_lomuto(a,l,p-1);quicksort_lomuto(a,p+1,r);}
    inline void quicksort_hoare(vector<int>&a, int l, int r) {if(l>=r) return;int p=hoare_partition(a,l,r);quicksort_hoare(a,l,p);quicksort_hoare(a,p+1,r);}
}
//using namespace utilities;
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; }
int n,q,x,y,light[667];
pair<int,int>query[maxn];
namespace soup1{
    map<vector<int>,bool>mp;
    int bfs(vector<int>&st) {
        queue<pair<vector<int>,int>>q;
        vector<int>en(st.size(),0);
        int ans=INT_MAX;
        q.push({st,0});
        while(!q.empty()) {
            auto[u,cd]=q.front();q.pop();
            // for(int i:u) cerr << i << ' ';
            // cerr << cd << '\n';
            if(mp[u]) continue;
            mp[u]=true;
            if(u==en) {ans=cd;break;}
            for(int i=0; i<u.size(); ++i) {
                for(int j=i+1; j<u.size(); ++j) {
                    int a=u[i],b=u[j];
                    u[i]=(a+1)%3,u[j]=(b+2)%3;
                    q.push({u,cd+1});
                    u[i]=(a+2)%3,u[j]=(b+1)%3;
                    q.push({u,cd+1});
                    u[i]=a,u[j]=b;
                }
            }
        }
        return ans;
    }
    void solve() {
        for(int k=1; k<=q; ++k) {
            auto[l,r]=query[k];
            vector<int>st;
            for(int i=l; i<=r; ++i) st.pb(light[i]);
            int ans=bfs(st);
            cout << (ans==INT_MAX?-1:ans) << '\n';
        }
    }
}
namespace soup2{
    void solve() {
        for(int k=1; k<=q; ++k) {
            int d1=0,d2=0;
            auto[l,r]=query[k];
            for(int i=l; i<=r; ++i) {if(light[i]==1)++d1;else if(light[i]==2)++d2;}
            long long ans=0;
            if(d1>d2) {
                    //cerr << 'a';
                ans+=d2;
                d1-=d2;
                if(!(d1%3)) {
                    ans+=(d1/3)<<1;
                    cout << ans << '\n';
                }
                else cout << -1 << '\n';
            }
            else {
                //cerr << 'a';
                ans+=d1;
                d2-=d1;
                if(!(d2%3)) {
                    ans+=(d2/3)<<1;
                    cout << ans << '\n';
                }
                else cout << -1 << '\n';

            }
        }
    }
}
namespace soup3{
    struct triple{int x,y,z;};
    map<pair<int,int>,bool>ump;
    int bfs(pair<int,int>st,int len) {
        ump.clear();
        int ans=INT_MAX;
        queue<pair<pair<int,int>,int>>q;
        q.push({st,0});
        while(!q.empty()) {
            auto[p,cd]=q.front();q.pop();
            auto [c1,c2]=p;
            if(!c1 && !c2) {ans=cd;break;}
            if(ump[p]) continue;
            ump[p]=true;
            int c0=len-c1-c2;
            vector<triple>v1,v2;
            for(int i=0; i<=x; ++i) {
                for(int j=0; j<=x-i; ++j) {
                    int k=x-i-j;v1.pb({i,j,k});

                }
            }
            for(int i=0; i<=y; ++i) {
                for(int j=0; j<=y-i; ++j) {
                    int k=y-i-j;v2.pb({i,j,k});
                }
            }
            for(int i=0; i<v1.size(); ++i) {
                for(int j=0; j<v2.size(); ++j) {
                    auto[x0,x1,x2]=v1[i];
                    auto[y0,y1,y2]=v2[j];
                    if(x0+y0>c0 || x1+y1>c1 || x2+y2>c2) continue;
                    int n1=c1-x1-y1+x0+y2, n2=c2-x2-y2+x1+y0;
                    q.push({{n1,n2},cd+1});
                }
            }
        }
        return ans;
    }
    void solve() {
        for(int k=1; k<=q; ++k) {
            auto[l,r]=query[k];
            int d1=0,d2=0;
            for(int i=l; i<=r; ++i) {
                if(light[i]==1) ++d1;
                else if(light[i]==2) ++d2;
            }
            int ans=bfs({d1,d2},r-l+1);
            cout << (ans==INT_MAX?-1:ans) << '\n';
        }
    }
}
namespace soup4{
    struct triple{int x,y,z;};
    vector<triple>v1,v2;
    int dist[667][667][667],pre[3][667];
    inline void bfs(int len) {
        queue<triple>q;
        q.push({len,0,0});
        dist[len][0][0]=0;
        while(!q.empty()) {
            auto[c0,c1,c2]=q.front();q.pop();
            //if(dist[c0][c1][c2]!=-1) continue;
            for(int i=0; i<v1.size(); ++i) {
                for(int j=0; j<v2.size(); ++j) {
                    auto[x0,x1,x2]=v1[i];
                    auto[y0,y1,y2]=v2[j];
                    if(x0+y0>c0 || x1+y1>c1 || x2+y2>c2) continue;
                    int n1=c1-x1-y1+x0+y2, n2=c2-x2-y2+x1+y0,n0=len-n1-n2;
                    if(n0<0 || n1<0 || n2<0) continue;
                    if(dist[n0][n1][n2]==-1) {
                        dist[n0][n1][n2]=dist[c0][c1][c2]+1;
                        q.push({n0,n1,n2});
                    }
                }
            }
        }
    }
    void solve() {
        swap(x,y);
        for(int i=0; i<=x; ++i) {
            for(int j=0; j<=x-i; ++j) {
                int k=x-i-j;v1.pb({i,j,k});

            }
        }
        for(int i=0; i<=y; ++i) {
            for(int j=0; j<=y-i; ++j) {
                int k=y-i-j;v2.pb({i,j,k});
            }
        }
        memset(dist,-1,sizeof(dist));
        //dist[0][0][0]=0;
        for(int i=1; i<=n; ++i) {
            pre[0][i]=pre[0][i-1],pre[1][i]=pre[1][i-1],pre[2][i]=pre[2][i-1];
            ++pre[light[i]][i];
        }
        for(int i=1; i<=n; ++i) bfs(i);
        for(int k=1; k<=q; ++k) {
            auto[l,r]=query[k];
            int c0=pre[0][r]-pre[0][l-1],c1=pre[1][r]-pre[1][l-1],c2=pre[2][r]-pre[2][l-1];
            cout << (dist[c0][c1][c2]) <<'\n';
        }
    }
}
namespace soupfull{
    struct triple{int x,y,z;};
    vector<triple>v1,v2;
    int dist[7][667][667],pre[3][667];
    void bfs(int len) {
        
    }
    void solve() {
        swap(x,y);
        for(int i=0; i<=x; ++i) {
            for(int j=0; j<=x-i; ++j) {
                int k=x-i-j;v1.pb({i,j,k});

            }
        }
        for(int i=0; i<=y; ++i) {
            for(int j=0; j<=y-i; ++j) {
                int k=y-i-j;v2.pb({i,j,k});
            }
        }
        memset(dist,-1,sizeof(dist));
        //dist[0][0][0]=0;
        for(int i=1; i<=n; ++i) {
            pre[0][i]=pre[0][i-1],pre[1][i]=pre[1][i-1],pre[2][i]=pre[2][i-1];
            ++pre[light[i]][i];
        }
    }
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("light")
    cin >> n >> q >> x >> y;
    for(int i=1; i<=n; ++i) cin >> light[i];
    for(int i=1; i<=q; ++i) cin >> query[i].fi >> query[i].se;
    if(q<=3) soup3::solve();
    else soup4::solve();
    return 0;

}
/**/
/*
5 3 1 1
2 2 2 2 1
1 5
2 4
3 5

*/
