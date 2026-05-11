#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
set<ll>st;
set<ll>p;
bool c=1;
/*void ptnt(ll n)
{
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            st.insert(i);
            while(n%i==0) n/=i;
        }
    }
}
void ptnt2(ll n)
{
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            if(st.find(i)==st.end()) {
                c=0;
                break;
            }
            p.insert(i);
            while(n%i==0) n/=i;
        }
    }
}*/
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll m,n,d=0;
    cin >> m >> n;
    ll a[m];
    ll cht=n;
    vector<ll>vp;
    for(ll i=0; i<m; i++) {
        cin >> a[i];
        ptnt(a[i]);
    }
    /*while(n--) {
        ll b[m];
        bool kt=1;
        for(ll i=0; i<m; i++) {
            cin >> b[i];
            ptnt2(b[i]);
            /*if(c==0) {
                kt=0;
                break;
            }
            cout << c << " ";
        }
        if(kt==1) {
            d++;
            vp.push_back(cht-n);
        }
        p.clear();
    }
    cout << d << "\n";
    for(ll i=0; i<vp.size(); i++) cout << vp[i] << " ";*/
    while(n--) {

    }

}
