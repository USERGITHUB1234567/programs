#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,q,a[maxn],p[maxn];
namespace soup3{
    long long cnt(int l, int r) {
        long long ans=((long long)(r-l)*(r-l+1))>>1;
        unordered_map<int,long long>ump;
        for(int i=l; i<=r; ++i) {
            ++ump[a[i]];
        }
        for(auto[u,v]:ump){
            ans-=((v)*(v-1))>>1;
        }
        return ans+1;
    }
    void solve() {
        vector<bool>active(n+1, true);
        //cout << cnt(3,n) << '\n';
        for(int t=1; t<=q; ++t) {
            active[p[t]]=false;
            long long ans=0;
            int l=1,r;
            for(int i=1; i<=n; ++i) {
                if(!active[i]) {
                    if(l!=-1) ans=max(ans,cnt(l,i-1));
                    l=-1;
                }
                else if(active[i] && l==-1) l=i;
            }
            ans=max(ans,cnt(l,n));
            cout << ans << '\n';
        }
        
    }
}
struct disjoint_set_union{
    int n;
    vector<int>p;
    vector<long long>m,s;
    vector<unordered_map<int,int>>freq;
    disjoint_set_union(int _n):n(_n) {
        p.resize(n+1);
        m.resize(n+1);
        s.resize(n+1);
        freq.resize(n+1);
        for(int i=1; i<=n; ++i) p[i]=i;
    }
    int root(int u) {return (u==p[u]?u:p[u]=root(p[u]));}
    void unite(int u, int v) {
        u=root(u),v=root(v);
        if(u!=v) {
            if(freq[v].size()>freq[u].size()) swap(u,v);
            for(auto[val,cnt]:freq[v]) {
                long long old=freq[u][val];
                s[u]-=((old)*(old-1))>>1;
                long long nw=old+cnt;
                s[u]+=(nw*(nw-1))>>1;
                freq[u][val]=nw;
            }
            p[v]=u;
            m[u]+=m[v];
            freq[v].clear();
        }
    }
    long long query(int u) {
        u=root(u);
        return (1+((m[u]*(m[u]-1))>>1)-s[u]);
    }
};
namespace soupfull{
    long long ans[maxn];
    void solve() {
        vector<bool>active(n+1,true);
        disjoint_set_union dsu(n);
        long long res=0;
        for(int i=1; i<=q; ++i) {active[p[i]]=false;}
        for(int i=1; i<=n; ++i) {
            if(active[i]) {
                dsu.m[i]=1;
                dsu.freq[i][a[i]]=1;
                if(i-1>0 && active[i-1]) dsu.unite(i,i-1);
                res=max(res,dsu.query(i));
            }
        }
        for(int i=q; i>=1; --i) {
            //cout << res << '\n';
            ans[i]=res;
            int u=p[i];
            active[u]=true;
            dsu.freq[u][a[u]]=1;
            dsu.m[u]=1;
            if(u-1!=0 && active[u-1]) dsu.unite(u,u-1);
            if(u+1<=n && active[u+1]) dsu.unite(u,u+1);
            res=max(res,dsu.query(u));
        }
        for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("3293.inp", "r", stdin);
    freopen("3293.out", "w", stdout);
    cin >> n >> q;for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=q; ++i) cin >> p[i];
    soup3::solve();
    //cout << '\n';
    //soupfull::solve();

}