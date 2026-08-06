#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q,a[maxn];
pair<int,int>query[maxn];
struct fenwick_tree{
    vector<long long>bit;
    int n;
    void add(int i, long long v) {
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
namespace soup3 {
    void implement() {

    }
}
int main(int argc, char** argv) {
    freopen("thaotac.inp", "r", stdin);
    freopen("thaotac.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=q; ++i) cin >> query[i].first >> query[i].second;
}