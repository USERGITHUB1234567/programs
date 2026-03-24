#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin >> n >> m;
    long long a[n];
    vector<long long>v;
    map<string,long long>mp;
    for(long long i=0; i<n; i++) cin >> a[i];
    string s[m];
    for(long long i=0; i<m; i++) {
        cin >> s[i];
        mp[s[i]]++;
    }
    for(auto x:mp) {
        v.push_back(x.second);
    }
    long long t=mp.size();
    sort(v.begin(), v.end(),greater<long long>());
    sort(a,a+n);
    long long mi=0,ma=0;
    for(long long i=0; i<t; i++) {
        mi+=v[i]*a[i];
    }
    //reverse(v.begin(),v.end());
    reverse(a,a+n);
    for(long long i=0; i<t; i++) {
        ma+=v[i]*a[i];
    }
    cout << mi << " " << ma;
}
