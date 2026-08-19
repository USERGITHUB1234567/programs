#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int tc;int n;
vector<int>g[maxn];
struct disjoint_set_union{
    vector<int>p;
    int n;
    disjoint_set_union(int _n):n(_n) {
        p.resize(n+1);
        for(int i=1; i<=n; ++i) p[i]=i;
    }
    int root(int u) {return (p[u]==u?u:p[u]=root(p[u]));}
    void unite(int u, int v) {
        u=root(u),v=root(v);
        if(u!=v) {p[v]=u;}
    }
    bool check(int u, int v) {return root(u)!=root(v);}
};
int main(int argc, char** argv) {
    cin >> tc;
    while(tc--) {
        int n;cin >> n;
        vector<array<int,3>>seg,edge;
        vector<array<int,4>>event;
        seg.reserve(n);
        event.reserve((n<<1));
        for(int i=1; i<=n; ++i) {
            int l,r,a;cin >> l >> r >> a;
            seg.push_back({l,r,a});
            event.push_back({l,1,i,a});
            event.push_back({r+1,-1,i,a});
        }
        sort(event.begin(),event.end());
        set<pair<int,int>>st;
        for(int i=0; i<event.size(); ++i) {
            auto[pos,type,id,a]=event[i];
            if(type==-1) {
                st.erase(st.find({a,id}));
            }else {
                auto it=st.lower_bound({a, 0});
                if(it!=st.end()) {
                    edge.push_back({abs(a-it->first),id,it->second});
                }
                if(it!=st.begin()) {
                    auto prev_it=prev(it);
                    edge.push_back({abs(a-prev_it->first),id,prev_it->second});
                }
                st.insert({a,id});
            }
        }
        sort(edge.begin(),edge.end());
        int comp=n;
        long long ans=0;
        disjoint_set_union dsu(n);
        for(auto[w,u,v]:edge) {
            if(dsu.check(u,v)) {
                ans+=w;
                --comp;
                dsu.unite(u,v);
            }
        }
        if(comp!=1) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}