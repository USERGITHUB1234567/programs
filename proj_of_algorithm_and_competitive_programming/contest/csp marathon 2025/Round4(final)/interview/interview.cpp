#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=152;
int n,l,r,k,a[maxn];
void soup1() {
    int t=r-l+1,kq=0;
    sort(a+1,a+1+n,greater<int>());
    for(int i=1; i<=t; i++) kq+=a[i];
    cout << kq;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> l >> r >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    soup1();
}