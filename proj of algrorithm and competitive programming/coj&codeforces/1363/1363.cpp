#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n ,k;
    cin >> n >> k;
    ll a[n],b[n];
    deque<ll>dq;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) {
        while(!dq.empty() and a[dq.back()]>=a[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.back()-dq.front()>=k) dq.pop_front();
        b[i]=a[dq.front()];
    }
    for(ll i=k-1; i<n; i++) cout << b[i] << "\n";
}
