#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<long long>pq;
    for(int i=1;i<=n; i++) {
        long long x;
        cin >> x;
        pq.push(-x);
    }
    long long t;
    while(!pq.empty() and pq.size()>1) {
        t=-pq.top();
        pq.pop();
        t=(t+-pq.top())/2;
        pq.pop();
        pq.push(-t);
        //cout << t << ' ';
    }
    cout << -pq.top();
    return 0;
}
