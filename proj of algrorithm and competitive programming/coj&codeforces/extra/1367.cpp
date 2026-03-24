#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
ll n,k,v[1000001],a[1000001];
deque<ll>dq;
int main()
{
    ll n,k,t=0;
    cin >> n >> k;
    for(ll i=1; i<=n; i++) cin >> v[i];
    sort(v+1,v+n+1);
    a[1]=1e9;
    for(ll i=2; i<=n; i++) a[i]=v[i]-v[i-1];
    ll ans=1e9;
    for(ll i=1; i<=n; i++) {
        while(!dq.empty() and a[dq.back()]>=a[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.back()-dq.front()>=n-k) dq.pop_front();
        if(i-(n-k)+1>=1) ans=min(ans,v[i]-v[i-n+k+1]+a[dq.front()]);
    }
    cout << ans;
    return 0;
}
