#include <bits/stdc++.h>
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;
bool a[10000001];
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    memset(a,true,sizeof(a));
    a[0]=a[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(a[i])
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                a[j]=false;
            }
        }
    }
    vector<pair<ll,ll>> ans;
    for(ll i=2;i<=n;i++)
    {
        if(a[i])
        {
            ll p=i, j=0;
            while(n/p!=0)
            {
                j+=n/p;
                p*=i;
            }
            ans.push_back({i,j});
        }
    }
    cout << ans.size()<<"\n";
    for(ll i=0;i<ans.size();i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
