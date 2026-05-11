#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
using namespace std;
ll a[500001];
ll nxt[500001];
ll lst[500001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k,p,kq=0;
    cin >> n >> k >> p;

    priority_queue<pair<ll,ll>>pq;
    for(ll i=1; i<=p; i++) {
        cin >> a[i];
    }
    for(ll i=1; i<=n; i++) lst[i]=p+1;
    for(ll i=p; i>0; i--) {
        nxt[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    bool used[500001];
    memset(used,false,sizeof(used));
    ll d=0;
    for(ll i=1; i<=p; i++) {
        if(used[a[i]]) pq.push({nxt[i],a[i]});
        else {
            if(d<k) d++;
            else {
                used[pq.top().second]=false;
                pq.pop();
            }
            kq++;
            used[a[i]]=1;
            pq.push({nxt[i],a[i]});
        }
    }
    cout << kq;
}
