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
const int maxn=1000006;
const ll inf=LLONG_MAX;
ll f[maxn][3],a[maxn],ans=0;
int n;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(f,-0x3f,sizeof(f));
    f[1][0]=0;
    f[1][1]=-a[1];
    //f[1][2]=-1;
    for(int i=2; i<=n; i++) {
        f[i][0]=max(f[i-1][0],f[i-1][1]+a[i]);
        f[i][1]=max({f[i-1][0]-a[i],f[i-1][1],f[i-1][2]+a[i]});
        f[i][2]=max(f[i-1][1]-a[i],f[i-1][2]);
        ans=max({ans,f[i][1],f[i][2],f[i][0]});
    }
    cout << ans;
}