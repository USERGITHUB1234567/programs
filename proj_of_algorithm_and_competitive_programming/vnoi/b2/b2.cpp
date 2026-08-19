#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<pair<long long,long long>> pttsnt(long long n)
{
    vector<pair<long long, long long>>pt;
    for(int i=2; i*i<=n; i++) {
        int d=0;
        while(n%i==0) {
            n/=i;
            d++;
        }
        if(d!=0) pt.push_back({i,d});
    }
    if(n>0) pq.push_back({n,1});
    return pt;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n,m;
        cin >> n >> m;
        vector<long long>kq;
        if(n==m) {
            cout << 0 << "\n";
            continue;
        }
        if(m%n!=0 || n>m || n==1) {
            cout << -1 << "\n";
            continue;
        }

        cout << "\n";
    }
}
