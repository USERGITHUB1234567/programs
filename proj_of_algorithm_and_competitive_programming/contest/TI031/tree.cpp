#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,a[maxn];
struct fenwick_tree{
    vector<int>bit;
    int m;
    fenwick_tree(int _m):m(_m) {bit.assign(m+1,0);}
    void add(int i, int v) {
        while(i<=m) {
            //cerr << i << ' ' << m << '\n';
            bit[i]+=v;
            i+=i&-i;
        }
    }
    int sum(int i) {
        int res=0;
        while(i) {
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
    int sum_range(int i, int j) {return sum(j)-sum(i-1);}
};
namespace soup1{
    void implement() {
        int ans=0;
        for(int i=2; i<=n; ++i) {
            //if(a[i]==0) cout << i << ' ';
            for(int j=i-1; j>=1; --j) {
                if(a[i]-a[j]>=0 && a[i]-a[j]<=k) ++ans;
            }
        }
        cout << ans;
    }
}
namespace soupfull{
    void implement() {
        int mx=*max_element(a+1,a+1+n);
        //sort(a+1,a+1+n);
        fenwick_tree fen(mx);
        long long ans=0;
        for(int i=1; i<=n; ++i) {
            int low=max(1,a[i]-k);
            ans+=fen.sum_range(low,a[i]);
            fen.add(a[i],1);
            //if(a[i]==0) cout << i << ' ';
        }
        cout << ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    soupfull::implement();
    //cout << '\n';
    //soup1::implement();
}
/*
4 2
9 7 7 8


*/
