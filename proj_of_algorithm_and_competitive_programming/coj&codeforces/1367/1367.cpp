#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=1000006;
int n,k,a[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    int l=1,r=n;
    while(k--) {
        if(abs(a[l]-a[l+1])>abs(a[r]-a[r-1])) l++;
        else r--;
    }
    int mi=INT_MAX,ma=*max_element(a+1+l,a+1+r)-*min_element(a+1+l,a+1+r);
    for(int i=l; i<r; i++) {
        mi=min(mi,abs(a[i]-a[i+1]));
        cout << a[i] << " " ;
    }
    cout << ma << " " << mi;
}