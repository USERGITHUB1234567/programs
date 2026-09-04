#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;
int n,a[maxn];
struct segment_tree{
    int st[(maxn<<2)+5];
    int n;
    segment_tree(int _n):n(_n) {for(int i=1; i<=(n<<2); ++i) st[i]=2e9;}
    void update(int id, int l, int r, int i, int v) {
        if(l>i || r<i) return;
        if(l==r) {
            st[id]=min(st[id],v);
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid)update(id<<1,l,mid,i,v);
        if(i>mid)update(id<<1|1,mid+1,r,i,v);
        st[id]=min(st[id<<1],st[id<<1|1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 2e9;
        if(l>=i && r<=j) return st[id];
        int mid=(l+r)>>1;
        return min(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
    }
};
namespace soupfull{
    vector<int>val,store;
    void implement() {
        segment_tree seg(n);
        val.reserve(n);
        for(int i=1; i<=n; ++i) val.push_back(a[i]);
        sort(val.begin(),val.end());
        val.erase(unique(val.begin(),val.end()),val.end());
        auto idx=[&](int id) {return lower_bound(val.begin(),val.end(),id)-val.begin()+1;};
        for(int i=1; i<=n; ++i) a[i]=idx(a[i]);
        int mx=val.size();
        for(int i=1; i<=n; ++i) {
            int t1=2e9,t2=2e9;
            if(a[i]!=1) t1=seg.query(1,1,n,1,a[i]-1);
            if(a[i]!=mx) t2=seg.query(1,1,n,a[i]+1,mx);
            int t=max({-1,i-t1,i-t2});
            store.push_back(t);
            seg.update(1,1,n,a[i],i);
        }
        sort(store.begin(),store.end());
        store.erase(unique(store.begin(),store.end()),store.end());
        // for(int i:store) cout << i << ' ';
        // cout << '\n';
        for(int k=2; k<=n; ++k) {
            auto it=lower_bound(store.begin(),store.end(),k);
            cout << *prev(it) << ' ';
        }
    }
}
namespace cookedsoup{
    void implement() {
        vector<int>pi(n+1,0);
        for(int i=2; i<=n; ++i) {
            int j=pi[i-1];
            while(j && a[i]!=a[j+1]) j=pi[j];
            j+=(a[i]==a[j+1]);
            pi[i]=j;
        }
        vector<bool>valid(n+1,true);
        valid[0]=false;
        int l=pi[n];
        while(l) {
            valid[n-l]=false;
            l=pi[l];
        }
        vector<int>ans(n+1,-1);
        int cur=-1;
        for(int i=1; i<=n; ++i) {
            if(valid[i]) cur=i;
            ans[i]=cur;
        }
        for(int i=2; i<=n; ++i) cout << ans[i-1] << ' ';
    }
}
int main(int argc, char** argv) {
    cin >> n;for(int i=1; i<=n; ++i) cin >> a[i];
    cookedsoup::implement();
}