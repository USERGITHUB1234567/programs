#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> p;
    while(n--) {
        long long a,b;
        cin >> a >> b;
        p.push_back({a,1});
        p.push_back({b,-1});
    }
    int kq=0;
    int cnt=0;
    sort(p.begin(),p.end());
    for(auto x:p) {
        cnt+=x.second;
        kq=max(kq,cnt);
    }
    cout << kq;
    return 0;
}
