#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
ll kt[10000001]={0};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    kt[0]=kt[1]=0;
    ll n;
    cin >> n;
    for(ll i=2; i*i<=n; i++) {
        if(kt[i]==0) {
            ll j=i*i;
            while(j<=1e7+1) {
                kt[j]=1;
                j+=i;
            }
        }
    }
    for(ll i=2; i<=n; i++) {
        if(kt[i]==0) cout << i << "\n";
    }
}
