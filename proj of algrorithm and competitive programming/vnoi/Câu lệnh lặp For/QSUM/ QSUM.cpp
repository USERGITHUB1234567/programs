#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q;
long long pre[maxn];
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1,x; i<=n; ++i) {cin >> x;pre[i]=pre[i-1]+x;}
    while(q--) {
        int l,r;cin >> l >> r;
        cout << pre[r]-pre[l-1] << '\n';
    }
}