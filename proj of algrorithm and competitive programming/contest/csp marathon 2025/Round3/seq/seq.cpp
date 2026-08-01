#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
long long a[maxn],res[maxn],n;
void soup1() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            res[i]+=abs(i-j)*abs(a[i]-a[j]);
        }
    }
    for(int i=1; i<=n; i++) {
        cout << res[i] << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("seq");
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    soup1();
}