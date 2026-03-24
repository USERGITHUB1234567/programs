#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
ll n,x,h[1000001],hmin[1000001]={0},hmax[1000001]={0};
int main()
{
    ll kd=1,kt=0;
    cin >> n >> x;
    for(ll i=1; i<=n; i++) cin >> h[i];
    deque<ll>dq;
    for(ll i=1; i<=n; i++) {
        while(!dq.empty() and h[dq.back()]>=h[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() and i-x>=dq.front()) dq.pop_front();
        if(i-x+1>=1) hmin[i-x+1]=h[dq.front()];
    }
    dq.clear();
    for(ll i=1; i<=n; i++) {
        while(!dq.empty() and hmin[dq.back()]<=hmin[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() and i-x>=dq.front()) dq.pop_front();
        hmax[i]=hmin[dq.front()];
    }
    for(ll i=1; i<=n; i++) {
        h[i]-=hmax[i];
        kt+=h[i];
    }
    ll vt=0;
    for(ll i=2; i<=n; i++) {
        if(hmax[i]==hmax[i-1]) vt++;
        if(vt>=x) {
            vt=0;
            kd++;
        }
        if(hmax[i]!=hmax[i-1]) {
            kd++;
            vt=0;
        }
    }
    cout << kt << "\n" << kd;
    //for(ll i=1; i<=n; i++) cout << hmin[i] << " ";
    return 0;
}
/*ll n ,x,kq=0,kd=0;
    cin >> n >> x;
    ll a[n],b[n],c[n];
    bool s[n];
    memset(s,false,n);
    deque<ll>dq;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        c[i]=a[i];
    }
    for(ll i=0; i<n; i++) {
        while(!dq.empty() and a[dq.back()]>=a[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty()&&dq.front() <= i-x) dq.pop_front();
        b[i]=dq.front();
    }
    ll t=min(n-1,x),l=0;
    //cout << t << endl;
    ll ct=x-1,g=ct;
    for(ll i=g; i<n; i++) {
        for(ll j=ct; j>=ct-x; j--) {
            if(s[i]==0) {
                s[i]=1;
                a[i]-=c[b[j]];
            }
            else break;
        }
        ct+=x;
    }
    if(ct<n-1) {
        for(ll i=ct; i<n; i++) a[i]-=c[b[n-1]];
    }
    for(ll i=0; i<n; i++) {
        if(a[i]>0) kq+=a[i];
    };
    //cout << endl;
    cout << kq << "\n" << kd;*/
