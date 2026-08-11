#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q;
vector<array<int,4>>adj[maxn];
struct query{int a,b;long long e;}qu[maxn];
array<int,5>road[maxn];
namespace soup1{
    int d[maxn];
    array<int,4>par[maxn];
    void dfs(int x, int p) {
        for(auto[y,v,c,s]:adj[x]) {
            if(y==p) continue;
            par[y]={x,v,c,s};
            d[y]=d[x]+1;
            dfs(y,x);
        }
    }
    int process(int a, int b, long long e) {
        if(d[a]<d[b]) swap(a,b);
        vector<array<int,3>>val;
        while(d[a]>d[b]) {
            auto[y,v,c,s]=par[a];
            val.push_back({v,c,s});
            a=y;
        }
        while(a!=b) {
            {
                auto[y,v,c,s]=par[a];
                val.push_back({v,c,s});
                a=y;
            }
            {
                auto [y,v,c,s]=par[b];
                val.push_back({v,c,s});
                b=y;
            }
            //cout << a << ' ' << b << '\n';
        }
        int mn1=val[0][2],mn2=val[0][0];
        for(auto[v,c,s]:val) {
            //cout << v << ' ' << c << ' ' << s << '\n';
            mn1=min(mn1,s),mn2=min(mn2,v);
        }
        int l=mn2,r=mn1+1;
        //cout << l << ' ' << r << '\n';
        auto cost=[&](int mid) {
            long long sum=0;
            for(auto[v,c,s]:val) {
                if(v<mid) sum+=c;
            }
            return sum;
        };
        int ans=l;
        while(l<r) {
            int mid=(long long)(l+r)>>1;
            //cout << mid << '\n';
            if(cost(mid)<=e) {l=mid+1;ans=mid;}
            else r=mid;
        }
        //cout << cost(12) << '\n';
        ///cout << l << '\n';
        return ans;
    }
    void implement() {
        dfs(1,0);
        for(int t=1; t<=q; ++t) {
            //auto[a,b]=query[t];
            auto[a,b,e]=qu[t];
            cout << process(a,b,e) << '\n';
        }
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("road.inp", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n;
    for(int i=1; i<n; ++i) {
        int x,y,v,c,s;
        cin >> x >> y >> v >> c >> s;
        adj[x].push_back({y,v,c,s});
        adj[y].push_back({x,v,c,s});
        road[i]={x,y,v,c,s};
    }
    cin >> q;
    for(int i=1; i<=n; ++i) cin >> qu[i].a >> qu[i].b >> qu[i].e;
    soup1::implement();
}