#pragma GCC optimize("O3,Ofast")
#include <iostream>
using namespace std;
int n,q;
int main(int argc, char** argv) {
    cin >> n >> q;long long pre[n+1];
    for(int i=1; i<=n; ++i) {long long x;cin >> x;pre[i]=pre[i-1]+x;}
    while(q--) {int l,r;cin >> l >> r;cout << pre[r]-pre[l-1] << '\n';}
}