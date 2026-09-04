#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n;
long long d;
array<long long,3>tree[maxn];
namespace soup1{
    void implement() {
        int fm=(1<<n);
        long long ans=0;
        for(int mask=0; mask<fm; ++mask) {
            vector<array<long long,3>>store;
            for(int bit=mask; bit; bit&=(bit-1)) {
                int i=__builtin_ctz(bit);
                store.push_back(tree[i+1]);
            }
            /*for(int i=0; i<n; ++i) {
                if(mask&(1<<i)) store.push_back(tree[i+1]);
            }*/
            sort(store.begin(),store.end(),[](array<long long,3>a, array<long long,3>b){
                 return a[1]<b[1];
            });
            bool ck=true;
            for(int i=1; i<store.size(); ++i) {
                if((store[i][1]==store[i-1][1]) || (store[i][0]!=store[i-1][0] && (abs(store[i][0]-store[i-1][0])<d))) {
                    //cout << i << ' ';
                    //cout << i << ' ' << store[i][1] << ' ' << store[i-1][1] << ' ' << store[i][0] << ' ' << store[i-1][0] << ' ' << (store[i][0]!=store[i-1][0]) << ' ' << (abs(store[i][0]-store[i-1][0])<d) << '\n';

                    ck=false;break;
                }
                //cout << store[i][0] << ' ' << store[i][1] << ' ' << store[i][2] << '\n';
            }
            //cout << '\n';
            //cout << mask << ' ' << ck << '\n';
            if(ck) {
                long long tmp=0;
                for(auto[t,h,v]:store) tmp+=v;
                //if(tmp>ans) cout << mask << '\n';
                ans=max(ans,tmp);
            }
        }
        cout << ans;
    }
}
namespace soup2{
    unordered_map<int,int>ump;
    void implement() {
        for(int i=1; i<=n; ++i) {
            int cand1=ump[tree[i][1]],cand2=tree[i][2];
            ump[tree[i][1]]=max(cand1,cand2);
        }
        long long ans=0;
        for(auto[u,v]:ump) ans+=v;
        cout << ans;
    }
}
struct segment_tree{
    long long st[maxn<<1];
    void update(int id, int l, int r, int i, long long v) {
        if(l>i || r<i) return;
        if(l==r) {
            st[id]=max(st[id],v);
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,i,v);
        else update(id<<1|1,mid+1,r,i,v);
        st[id]=max(st[id<<1],st[id<<1|1]);
    }
    long long query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int mid=(l+r)>>1;
        return max(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
    }
}seg;
namespace soupfull{
    vector<array<long long,3>>store[maxn];
    void implement() {
        vector<int>val;
        val.reserve(n);
        for(int i=1; i<=n; ++i) {
            val.push_back(tree[i][1]);
        }
        sort(val.begin(),val.end());
        val.erase(unique(val.begin(),val.end()),val.end());
        auto get=[&](int x) {return lower_bound(val.begin(),val.end(),x)-val.begin()+1;};
        for(int i=1; i<=n; ++i) {
            int id=get(tree[i][1]);
            store[id].push_back(tree[i]);
        }
        int m=0,mx=val.size();
        for(int i=1; i<=n; ++i) m=max((long long)m,tree[i][0]);
        long long ans=0;
        for(int i=1; i<=mx; ++i) {
            vector<pair<long long,int>>tot;
            tot.reserve(store[i].size());
            for(int j=0; j<store[i].size(); ++j) {
                auto[t,h,v]=store[i][j];
                long long cand=v;
                cand+=seg.query(1,1,m,t,t);
                if(t-d>=1) {
                    int p1=max(1ll,t-d);
                    cand=max(cand,v+seg.query(1,1,m,1,p1));
                }
                if(t+d<=m) {
                    int p2=min((long long)m,t+d);
                    cand=max(cand,v+seg.query(1,1,m,p2,m));
                }
                ans=max(ans,cand);
                tot.push_back({cand,t});
            }
            for(auto[u,v]:tot) {
                seg.update(1,1,m,v,u);
            }
        }
        cout << ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //freopen("ecorest.inp", "r", stdin);
    //freopen("ecorest.out", "w", stdout);
    cin >> n >> d;
    for(int i=1; i<=n; ++i) cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    //if(n<=25)soup1::implement();
    //cout << '\n';
    //else soup2::implement();
    soupfull::implement();
}
/*
6 2
2 10 10
4 20 20
2 20 15
1 30 30
3 40 40
4 50 50
*/