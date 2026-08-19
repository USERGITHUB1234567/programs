#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,q,a[maxn],f[maxn];
array<int,3>query[maxn];
vector<int>val[maxn];
void init() {
    for(int i=1; i<(maxn>>1); i+=2) {
        f[i]=i;
        for(int j=(i<<1); j<maxn; j+=i) {
            f[j]=max(f[j],i);
        }
    }
}
namespace soup1{
    void implement() {
        for(int t=1; t<=q; ++t) {
            auto[type,u,v]=query[t];
            if(type==1) {
                
            }
        }
    }
}
int main(int argc, char** argv) {
    //cin >> n >> q;
    init();
    //for(int i=1; i<=1000; ++i) cout << f[i] << ' ';
    //for(int i=1; i<=q; ++i) cin >> query[i][0] >> query[i][1] >> query[i][2];
}