#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=102;
int a[maxn][maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n==1) cout << 1 << "\n";
        else if (n == 2) {
            int ans=4;
            cout << ans << "\n";
        }
        else {
            int ans=n;
            ans=(ans*ans+1)/2;
            cout << ans << "\n";
        }
    }
}