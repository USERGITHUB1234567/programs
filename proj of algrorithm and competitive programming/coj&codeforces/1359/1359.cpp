#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,k;
    cin >> n >> k;
    pair<long long,long long>p[n];
    priority_queue<long long>pq;
    for(long long i=0; i<k; i++) pq.push(0);
    for(long long i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        //cout << pq.top() << endl;
        cout << max(pq.top()*-1,p[i].first)+p[i].second << "\n";
        pq.push((max(pq.top()*-1,p[i].first)+p[i].second)*-1);
        pq.pop();
    }
}
