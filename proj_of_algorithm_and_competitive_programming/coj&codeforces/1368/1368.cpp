#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
deque<ll>dq;
int main()
{
    ll n,k;
    cin >> n >> k;
    ll a[n],b[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        if(i<k-1) dq.push_back(i);
    }
    b[0]=a[0];

}
