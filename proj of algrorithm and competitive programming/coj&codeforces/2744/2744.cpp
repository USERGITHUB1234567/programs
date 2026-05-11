#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=502;
int t,n;
bool mk[maxn][maxn];
int a[maxn][maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) mk[i][j]=false;
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                if(j==1 || j==i) {
                    mk[i][j]=true;
                }
            }
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                cout << mk[i][j] << " ";
            }
            cout << "\n";
        }
    }
}