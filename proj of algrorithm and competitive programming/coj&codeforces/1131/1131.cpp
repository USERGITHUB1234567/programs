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
    pair<long long,long long>p[n];
    for(long long i=0; i<n; i++) {
        long long a,b;
        cin >> a >> b;
        p[i].first=min(a,b);
        p[i].second=max(a,b);
    }
    vector<long long>v;
    sort(p,p+n,cmp);
    v.push_back(p[0].second);
    for(long long i=1; i<n; i++) {
        if(p[i].first>v.back()) v.push_back(p[i].second);
    }
    cout << v.size() << endl;
    for(long long i=0; i<v.size(); i++) cout << v[i] << " ";
}
