#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    if(n>m) {
        cout << 0;
        return 0;
    }
    int t=1,tmp=n;
    while(tmp>0) {
        t*=10;
        tmp/=10;
    }
    int ans=(m-n)/t+1;
    cout << ans;
}