#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,m,k;
vector<long long>v;
map<long long, long long>mp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            long long x;
            cin >> x;
            mp[x]++;
        }
    }
    for(auto x:mp) {
        v.push_back(x.second);
    }
    long long kq=0;
    sort(v.begin(),v.end(),greater<long long>());
    for(int i=0; i<k; i++) {
        kq+=v[i];
    }
    cout << kq;
}
