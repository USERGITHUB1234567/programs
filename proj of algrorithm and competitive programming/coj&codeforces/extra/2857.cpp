/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;
const ll slpt = 1e7;
pair<bool, ll> snt[slpt];
pair<ll, ll> p[slpt];

void msnt() {
    ll vtc = 1;
    snt[0].first = snt[1].first = true;
    for (ll i = 2; i * i < slpt; i++) {
        if (!snt[i].first) {
            snt[i].second = vtc;
            vtc++;
            for (ll j = i * i; j < slpt; j += i) {
                snt[j].first = true;
            }
        }
    }
}

void kvt() {
    ll h = 1, c = 1;
    for (ll i = 2; i < slpt; i++) {
        if (!snt[i].first) {
            if (c > h) {
                c = 1;
                h++;
            }
            p[snt[i].second].first = h;
            p[snt[i].second].second = c;
            c++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    msnt();
    kvt();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (!snt[n].first) {
            cout << p[snt[n].second].first << " " << p[snt[n].second].second << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define forr(i,x,y) for(ll i=x;i>=y;--i)
#define ford(i,x,y) for(ll i=x;i<=y;++i)
#define fi first
#define se second
#define __ <<" "<<
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
using namespace std;
const ll mx=1e7+1;
bool p[mx];
pair<ll,pair<ll,ll>>k[mx];
void era(ll n)
{
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for(ll i=2;i*i<=n;++i)
        if(p[i])
            for(ll j=i*i;j<=n;j+=i)p[j]=false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //file("2857");
    ll t;
    cin>>t;
    vector<ll>a(t);
    ford(i,0,t-1)cin>>a[i];
    ll n=*max_element(a.begin(),a.end());
    era(n);
    ll cnt1=1,cnt2=1;
    ford(i,2,n)
    {
        if(p[i])
        {
            k[i]={i,{cnt1,cnt2}};
            if(cnt1==cnt2)
            {
                cnt1++;
                cnt2=1;
            }
            else
                cnt2++;
        }
    }
    ford(i,0,t-1)
    {
        if(p[a[i]])
        {
            cout<<k[a[i]].se.fi __ k[a[i]].se.se;
        }
        else
            cout<<-1;
        cout<<"\n";
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e7 + 1;
bool p[mx];
pair<ll, pair<ll, ll>> k[mx];

void snt(ll n) {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (ll i = 2; i * i <= n; ++i)
        if (p[i])
            for (ll j = i * i; j <= n; j += i) p[j] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll t;
    cin >> t;
    vector<ll> a(t);
    for (ll i = 0; i < t; ++i) cin >> a[i];

    ll n = *max_element(a.begin(), a.end());
    snt(n);

    ll cnt1 = 1, cnt2 = 1;
    for (ll i = 2; i <= n; ++i) {
        if (p[i]) {
            k[i] = {i, {cnt1, cnt2}};
            if (cnt1 == cnt2) {
                cnt1++;
                cnt2 = 1;
            } else cnt2++;
        }
    }

    for (ll i = 0; i < t; ++i) {
        if (p[a[i]]) cout << k[a[i]].second.first << " " << k[a[i]].second.second;
        else cout << -1;
        cout << "\n";
    }

    return 0;
}
