#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<int> solve(vector<int> &a)
{
    if(a.size()<=1) return a;
    bool same = true;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[0]) {
            same = false;
            break;
        }
    }
    if (same) return a;
    vector<int>c,l;
    c.reserve(a.size());
    l.reserve(a.size());
    for(int i:a) {
        if(i&1) l.push_back((i-1)/2);
        else c.push_back(i/2);
    }
    vector<int>ro=solve(l),re=solve(c);
    vector<int>kq;
    kq.reserve(a.size());
    for(int i:ro) kq.push_back(i*2+1);
    for(int i:re) kq.push_back(i*2);
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(),a.end());
        auto ans=solve(a);
        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
/*
2
3
1 2 3
3
1 1 1
*/
