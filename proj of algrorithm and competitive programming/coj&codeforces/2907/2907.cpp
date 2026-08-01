#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long t=1e18;
    pair<long long,long long>p[n];
    for(int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        t=min(p[i].first+p[i].second/2-1,t);
        if(p[i].second%2==1) t++;
    }
    cout << t;
}
