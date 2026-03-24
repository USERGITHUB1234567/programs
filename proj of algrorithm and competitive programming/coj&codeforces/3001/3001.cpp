#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int m,n,a[maxn],b[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m;
    for(int i=1; i<=m; i++) cin >> a[i];
    cin >> n;
    for(int i=1; i<=n; i++) cin >> b[i];
    sort(b+1,b+1+n);
    for(int i=1; i<=m; i++) {
        int p=lower_bound(b+1,b+1+n,a[i])-b;
        if(p==1) cout << abs(b[p]-a[i]) << "\n";
        else {
            cout << min(abs(b[p]-a[i]),abs(b[p-1]-a[i])) << "\n";
        }
    }
}
