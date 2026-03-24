#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,k;
    double t=0;
    cin >> n >> m >> k;
    long long a[n],b[n];
    deque<long long>dq;
    for(long long i=0; i<n; i++) cin >> a[i];
    for(long long i=0; i<n; i++) {
        while(!dq.empty() and a[dq.back()]>=a[i]) dq.pop_back();
        dq.push_back(i);
        if(a[dq.back()]-a[dq.front()]>=k) dq.pop_front();
        b[i]=a[dq.front()];
        t+=b[i];
    }
    cout << setprecision(4) << fixed << t/n;
}
