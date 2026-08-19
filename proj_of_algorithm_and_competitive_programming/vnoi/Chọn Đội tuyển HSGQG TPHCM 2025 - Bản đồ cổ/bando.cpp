#include <bits/stdc++.h>
using namespace std;
const int maxn=1000006;
int n,k,cnt[maxn],par[maxn];
int root(int u) {return u==par[u]?u:par[u]=root(par[u]);}
int main(int argc, char** argv) {
    freopen("bando.inp", "r", stdin);
    freopen("bando.out", "w", stdout);
    cin >> n >> k;
    int l=0,r=n;
    for(int i=0; i<=n; ++i) {cnt[i]=1;par[i]=i;}
    for(int i=1; i<=k; ++i) {
        int pos;cin >> pos;
        pos=root(pos);
        //cerr << pos << '\n';
        if(pos-l<=r-pos) {
            for(int j=l; j<pos; ++j) {
                cnt[pos+(pos-j)]+=cnt[j];
                par[j]=pos+pos-j;
            }
            l=pos;
        }
        else {
            for(int j=r; j>pos; --j) {
                cnt[pos-(j-pos)]+=cnt[j];
                par[j]=pos-j+pos;
            }
            r=pos;
        }
        //for(int j=0; j<=n; ++j) cout << cnt[j] << ' ';
        //cout << '\n';
    }
    cout << r-l+1 << '\n';
    for(int i=l; i<=r; ++i) cout << cnt[i] << ' ';
}