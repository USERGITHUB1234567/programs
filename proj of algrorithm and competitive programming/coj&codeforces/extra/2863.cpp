#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
ll kt[10000000]={0};
void snt()
{
    for(ll i=2; i*i<=10000000; i++) {
        if(kt[i]==0) {
            ll j=i*i;
            while(j<=1e7) {
                if(kt[j]==0)kt[j]=i;
                j+=i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    snt();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        //cout << kt[n] << "\n";
        if(kt[n]==0) cout << n << "\n";
        else cout << kt[n] << "\n";
    }
}
