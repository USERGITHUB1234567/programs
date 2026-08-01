#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=100005;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n==2) {
            cout << -1 << " " << 2 << "\n";

        }
        else {
            if(n&1) {
                for(int i=1; i<=n; i++) {
                    cout << (i&1?-1:3) << ' ' ;
                }
                cout << "\n";
            }
            else {
                for(int i=1; i<n; i++) {
                    cout << (i&1?-1:3) << ' ' ;
                }
                cout << 2 << "\n";
            }
        }
    }
}