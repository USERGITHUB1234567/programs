#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int h[maxn],n,k,kq[maxn],mk1[maxn],mk2[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> h[i];
    //memset(kq,1,sizeof(kq));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=1; i<=n; i++) {
        while(!pq.empty() && (pq.top().first+k<h[i])) {
            mk1[pq.top().second]=i;
            pq.pop();
        }
        pq.push({h[i],i});
    }
    while(!pq.empty()) {
        mk1[pq.top().second]=n+1;
        pq.pop();
    }
    for(int i=n; i>=1; i--) {
        while(!pq.empty() && (pq.top().first+k<h[i])) {
            mk2[pq.top().second]=i;
            pq.pop();
        }
        pq.push({h[i],i});
    }
    while(!pq.empty()) {
        mk2[pq.top().second]=0;
        pq.pop();
    }
    for(int i=1; i<=n; i++) {
        cout << (mk1[i]-mk2[i]-1) << " ";
    }
}
