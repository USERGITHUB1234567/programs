#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q,query[maxn];
vector<int>s[maxn];
namespace souptrau{
    void implement() {
        for(int t=1; t<=q; ++t) {
            int a=query[t];
            int mx=0,ans=n;
            for(int i=n; i>=1; --i) {
                int p=lower_bound(s[i].begin(),s[i].end(),a)-s[i].begin();
                //cout << s[i].size()-p << ' ';
                if(s[i].size()-p>mx) {
                    mx=s[i].size()-p;
                    ans=i;
                }
            }
            cout << ans << '\n';
        }
    }
}
int cnt[maxn],ans[maxn];
vector<pair<int,int>>qu,island;
struct segment_tree{
    pair<int,int>st[maxn<<2];
    pair<int,int>mer(pair<int,int>a,pair<int,int>b) {
        pair<int,int>res;
        if(a.first>b.first) res=a;
        else if(a.first<b.first) res=b;
        else res={a.first,max(a.second,b.second)};
        return res;
    }
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]={cnt[l],l};
            return;
        }
        int mid=(l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        st[id]=mer(st[id<<1],st[id<<1|1]);
    }
    inline void update(int id, int l, int r, int i, int v) {
        if(l>i || r<i) return;
        if(l==r) {
            st[id].first+=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,i,v);
        else update(id<<1|1,mid+1,r,i,v);
        st[id]=mer(st[id<<1],st[id<<1|1]);
    }
    inline pair<int,int>query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return {0,0};
        if(l>=i && r<=j) return st[id];
        int mid=(l+r)>>1;
        return mer(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
    }
}seg;
namespace soupfull{
    void implement() {
        qu.reserve(q);
        for(int i=1; i<=q; ++i) {
            int a=query[i];
            qu.push_back({a,i});
        }
        for(int i=1; i<=n; ++i) {
            cnt[i]=s[i].size();
            for(int j:s[i]) island.push_back({j,i});
        }
        sort(qu.begin(),qu.end());
        sort(island.begin(),island.end());
        seg.build(1,1,n);
        int i=0;
        for(auto[a,id]:qu) {
            while(i<island.size() && island[i].first<a) {
                //fen.add(island[i].second,-1);
                seg.update(1,1,n,island[i].second,-1);
                --cnt[island[i].second];
                ++i;
            }
            ans[id]=seg.query(1,1,n,1,n).second;
            //ans[id]=fen.sum(n).second;
        }
        for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //freopen("islands.inp", "r", stdin);
    //freopen("islands.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        int c;cin >> c;
        s[i].reserve(c);
        for(int j=1; j<=c; ++j) {
            int x;cin >> x;
            s[i].push_back(x);
        }
        //for(int j:s[i]) cout << j << ' ';
        sort(s[i].begin(),s[i].end());
    }
    for(int i=1; i<=q; ++i) cin >> query[i];
    if(n<=1000 && q<=1000)souptrau::implement();
    //cout << '\n';
    else soupfull::implement();
}
