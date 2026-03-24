#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=500005;
int n,a[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    int kq=0;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n,greater<int>());
    for(int i=1; i<=n; i++) {
        if(a[i]>=i) kq=i;
        else break;
    }
    cout << kq;
}