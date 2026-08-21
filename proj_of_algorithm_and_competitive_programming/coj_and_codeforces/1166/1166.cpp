#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
vector<pair<ll,ll>>v;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) v.push_back({i,0});
        while(n%i==0) {
            v.back().second++;
            n/=i;
        }
    }
    if(n>1) v.push_back({n,1});
    cout << v.size() << "\n";
    for(ll i=0; i<v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
