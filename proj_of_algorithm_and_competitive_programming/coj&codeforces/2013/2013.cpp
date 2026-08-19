#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long long n,h[100001], ans=0;
    cin >> n;
    vector<pair<long long,long long>>p;
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n-1; i++) {
        if(h[i]<h[i+1]) {
            p.push_back({h[i],1});
            p.push_back({h[i+1],-1});
        }
        else {
            p.push_back({h[i],-1});
            p.push_back({h[i+1],1});
        }
    }
    sort(p.begin(),p.end());
    int kq=0,cnt=0;
    for(auto x:p) {
        cnt+=x.second;
        kq=max(kq,cnt);
    }
    cout << kq;
    return 0;
}
