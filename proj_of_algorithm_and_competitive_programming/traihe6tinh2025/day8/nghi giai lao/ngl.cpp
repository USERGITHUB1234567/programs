#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ford(a,b,c) for(int a = b; a <= c; a++)
#define fti(a,b,c) for(int a = b; a >= c; a--)
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define siz size()
#define pll pair<long long,long long>
#define pii pair<int,int>
#define ll long long
#define ms(a,b) memset(a,b,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb(x) push_back
#define fi first
#define se second
using namespace std;
vector<ll> a(100001,0),p(100001,0);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ford(i,1,n)
        cin >> a[i];
    sort(a.begin()+1,a.begin()+n+1,greater<ll>());
    ford(i,1,n)
        p[i]=p[i-1]+a[i];
    ll res=p[n]+1LL*(n-1)*3600;
    ford(k,1,n) {
        ll s=0,hs=1;
        for(int i=1;i<=n;i+=k) {
            int ide=min(n,i+k-1);
            ll sum=p[ide]-p[i-1];
            s+=sum*hs;
            if(s>=res) {
                break;
            }
            if(hs>LLONG_MAX/2) {
                s=res;
                break;
            }
            hs*=2;
        }
        if(s>=res)
            continue;
        res=min(res,s+(ll)(k-1)*3600);
    }
    cout << res;
    return 0;
}
