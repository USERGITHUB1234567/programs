#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long,long long>u,pair<long long,long long>v)
{
    return (u.second<v.second) or (u.second==v.second and u.first<v.first);
}
int main()
{
    long long n;
    cin >> n;
    long long t=0,a=0;
    pair<long long,long long>p[n];
    for(long long i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        t=max(t,p[i].second-p[i].first);
    }
    sort(p,p+n);
    long long a1=0,a2=0;
    long long l=p[0].first;
    long long r=p[0].second;
    for(long long i=1; i<n; i++) {
        if(p[i].first<=r) r=max(r,p[i].second);
        else {
            a1=max(a1,r-l);
            a2=max(a2,p[i].first-r);
            l=p[i].first;
            r=p[i].second;
        }
    }
    a1=max(a1,r-l);
    cout << a1 << " " << a2;
}
