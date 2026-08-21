#include <bits/stdc++.h>
using namespace std;
struct fenwick_tree{
    vector<long long>bit;
    int n;
    fenwick_tree(int _n):n(_n) {bit.assign(n+1,0);}
    void add(int i, int v) {
        while(i<=n) {
            bit[i]+=v;
            i+=i&-i;
        }
    }
    long long sum(int i) {
        long long res=0;
        while(i) {
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
};
int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n,m;cin >> n >> m;
        vector<vector<int>>a;
        vector<int>v;
        v.resize(n+1);
        a.assign(n+1,vector<int>(m+1));
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin >> a[i][j];
        multiset<int>store;
        for(int i=1; i<=n; ++i) {

        }
    }
}