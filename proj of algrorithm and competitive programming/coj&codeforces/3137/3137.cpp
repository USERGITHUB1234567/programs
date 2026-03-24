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
const int maxn=500005;
int n;
bool a[maxn];
vector<int>adj[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1,u,v; i<=n; ++i) {
        cin >> a[i];
        if(i<n) {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
}