#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=11;
int a[maxn],b[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,kq=0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) cin >> b[i];
        for(int i=1; i<=n; i++) {
            kq+=max(0,a[i]-b[i]);
        }
        cout << ++kq << "\n";
    }
}