#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
long long tx,ty;
pair<long long, long long> p[32];
void g(int s,int e,vector<pair<long long,long long>>& a,long long x=0,long long y=0) {
    if (s==e) {
        a.emplace_back(x,y);
        return;
    }
    g(s+1,e,a,x,y);
    g(s+1,e,a,x+p[s].first,y+p[s].second);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> p[i].first >> p[i].second;
    }
    cin >> tx >> ty;
    vector<pair<long long, long long>> a,b;
    g(0,n/2,a);
    g(n/2,n,b);
    sort(b.begin(),b.end());
    int c = 0;
    for (const auto& s:a) {
        long long x=tx-s.first;
        long long y=ty-s.second;
        c+=upper_bound(b.begin(),b.end(),make_pair(x,y))-lower_bound(b.begin(),b.end(),make_pair(x, y));
    }
    cout << c;
    return 0;
}
