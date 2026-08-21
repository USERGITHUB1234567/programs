#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,q,a[maxn];
vector<int>adj[maxn];
array<int,3>query[maxn];
namespace soup1{
    int d[maxn],up[maxn];
    void dfs(int u, int p) {
        for(int v:adj[u]) {
            if(v!=p) {
                d[v]=d[u]+1;
                up[v]=u;
                dfs(v,u);
            }
        }
    }
    void update(int u, int v, int w) {
        if(d[u]<d[v]) swap(u,v);
        while(d[u]>d[v]) {
            a[u]=a[u]%w;
            u=up[u];
        }
        while(u!=v) {
            a[u]=a[u]%w;
            a[v]=a[v]%w;
            u=up[u],v=up[v];
        }
        a[u]=a[u]%w;
    }
    void implement() {
        dfs(1,0);
        for(int t=1; t<=q; ++t) {
            auto[x,y,w]=query[t];
            update(x,y,w);
            //if(t==1) {cout << 0 << '\n';continue;}
            long long ans=0;
            for(int i=1; i<=n; ++i) {
                ans+=a[i]%t;
                //cout << a[i] << ' ';
            }
            cout << ans << '\n';
        }
    }
}
struct fenwick_tree {
    vector<int> bit;
    int size;

    void init(int _n) {
        size = _n;
        bit.assign(size + 1, 0);
    }

    void update(int i, int v) {
        while (i <= size) {
            bit[i] += v;
            i += i & -i;
        }
    }

    int sum(int i) {
        if (i <= 0) return 0;
        if (i > size) i = size;
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }

    int range(int i, int j) {
        if (i > j) return 0;
        return sum(j) - sum(i - 1);
    }
};
struct segment_tree {
    int size;
    vector<pair<int, int>> st;

    void init(int _n) {
        size = _n;
        st.assign((size + 5) << 2, {-1, -1});
    }

    pair<int, int> mer(pair<int, int> x, pair<int, int> y) {
        if (x.first >= y.first) return x;
        return y;
    }

    void build(int id, int l, int r, const int* rev, const int* val_arr) {
        if (l == r) {
            st[id] = {val_arr[rev[l]], l};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, rev, val_arr);
        build(id << 1 | 1, mid + 1, r, rev, val_arr);
        st[id] = mer(st[id << 1], st[id << 1 | 1]);
    }

    void update(int id, int l, int r, int i, int v) {
        if (l > i || r < i) return;
        if (l == r) {
            st[id] = {v, l};
            return;
        }
        int mid = (l + r) >> 1;
        if (i <= mid) update(id << 1, l, mid, i, v);
        else update(id << 1 | 1, mid + 1, r, i, v);
        st[id] = mer(st[id << 1], st[id << 1 | 1]);
    }

    pair<int, int> query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return {-1, -1};
        if (l >= i && r <= j) return st[id];
        int mid = (l + r) >> 1;
        return mer(query(id << 1, l, mid, i, j), query(id << 1 | 1, mid + 1, r, i, j));
    }
};

namespace soup2{
    vector<int>store1,store2;
    //fenwick_tree fen(n);
    void remove1(int l, int r) {
        auto it1=lower_bound(store1.begin(),store1.end(),l),it2=upper_bound(store1.begin(),store1.end(),r);
        //if(it1==store1.end() || *it1>r) return;
        //--it2;
        store1.erase(it1,it2);
    }
    void remove2(int l, int r) {
        auto it1=lower_bound(store2.begin(),store2.end(),l),it2=upper_bound(store2.begin(),store2.end(),r);
        //if(it1==store2.end() || *it1>r) return;
        //--it2;
        store2.erase(it1,it2);
    }
    void implement() {
        for(int i=1; i<=n; ++i) {
            if(a[i]==1) store1.push_back(i);
            else if(a[i]==2) store2.push_back(i);
        }
        //cout << store1.size() << ' ' << store2.size() << '\n';
        for(int t=1; t<=q; ++t) {
            auto[x,y,w]=query[t];
            if(y<x) swap(x,y);
            if(w==1) {remove1(x,y);remove2(x,y);}
            else if(w==2) {remove2(x,y);}
            if(t==1) {cout << 0 << '\n';}
            else if(t==2) {cout << store1.size() << '\n';}
            else {cout << store1.size()+2*store2.size() << '\n';}
        }
        // remove2(2,4);
        // cout << store2.size();
    }
}
namespace soup3{
    int cnt[maxn];
    long long sum(int t) {

    }
    void implement() {
        for(int i=1; i<=n; ++i) {
            ++cnt[a[i]];
        }
        for(int t=1; t<=q; ++t) {
            auto[x,y,w]=query[t];
            --cnt[a[x]];
            a[x]%=w;
            ++cnt[a[x]];

        }
    }
}
namespace soupfull {
    int par[maxn], heavy[maxn], pos[maxn], head[maxn], d[maxn], rev[maxn], cur;
    const int MAX_VAL=200000;
    long long total_sum = 0;
    fenwick_tree bit_cnt;
    segment_tree seg;

    int dfs(int u, int p) {
        int sz = 1, szm = 0;
        heavy[u] = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            d[v] = d[u] + 1;
            par[v] = u;
            int csz = dfs(v, u);
            if (csz > szm) {
                heavy[u] = v;
                szm = csz;
            }
            sz += csz;
        }
        return sz;
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = ++cur;
        rev[cur] = u;
        if (heavy[u]) decompose(heavy[u], h);
        for (int v : adj[u]) {
            if (v != par[u] && v != heavy[u]) decompose(v, v);
        }
    }

    void update_range(int l, int r, int w) {
        while (true) {
            auto res = seg.query(1, 1, n, l, r);
            if (res.first < w) break;
            int p = res.second;
            int node = rev[p];
            int val = a[node];
            int new_val = val % w;
            bit_cnt.update(val + 1, -1);
            bit_cnt.update(new_val + 1, 1);
            total_sum += (new_val - val);
            a[node] = new_val;
            seg.update(1, 1, n, p, new_val);
        }
    }

    void hld_update(int u, int v, int w) {
        for (; head[u] != head[v]; u = par[head[u]]) {
            if (d[head[u]] < d[head[v]]) swap(u, v);
            update_range(pos[head[u]], pos[u], w);
        }
        if (d[u] > d[v]) swap(u, v);
        update_range(pos[u], pos[v], w);
    }

    long long query_ans(int t) {
        if (t > MAX_VAL) return total_sum;
        long long total_floor_sum = 0;
        for (int k = 1; k * t <= MAX_VAL; ++k) {
            int L = k * t;
            int R = min(MAX_VAL, (k + 1) * t - 1);
            int cnt = bit_cnt.range(L + 1, R + 1);
            total_floor_sum += 1LL * k * cnt;
        }
        return total_sum - 1LL * t * total_floor_sum;
    }

    void implement() {
        cur = 0;
        total_sum = 0;
        bit_cnt.init(MAX_VAL + 5);
        seg.init(n);

        d[1] = 0;
        par[1] = 0;
        dfs(1, 0);
        decompose(1, 1);

        for (int i = 1; i <= n; ++i) {
            total_sum += a[i];
            bit_cnt.update(a[i] + 1, 1);
        }

        seg.build(1, 1, n, rev, a);

        for (int t = 1; t <= q; ++t) {
            auto [x, y, w] = query[t];
            hld_update(x, y, w);
            cout << query_ans(t) << '\n';
        }
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("3294.inp", "r", stdin);
    freopen("3294.out", "w", stdout);
    cin >> n >> q;
    bool cks2=true;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(min(u,v)+1!=max(u,v) || a[i]>2) {cks2=false;}
    }
    for(int i=1; i<=q; ++i) cin >> query[i][0] >> query[i][1] >> query[i][2];
    //if(cks2)soup2::implement();
    //cout << '\n';
    //else soup1::implement();
    //soup2::implement();
    //cout << '\n';
    //soup1::implement();
    soupfull::implement();
}
/*
7 3
1 2 1 2 2 1 1
1 2
2 3
3 4
4 5
5 6
6 7
1 3 3
2 4 2
3 5 1
*/