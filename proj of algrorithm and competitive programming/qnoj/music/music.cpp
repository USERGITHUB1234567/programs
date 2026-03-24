#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t,n,f[502],a[502];
void souptl()
{
    int re[n+1];
    pair<int,int> p[n+1];
    memset(re,0,sizeof(re));
    for(int i=1; i<=n; i++) {
        p[i].first=a[i];
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    vector<pair<int,int>>v1,v2;
    for(int i=n; i>=1; i--) {
        if(i%2==1) v1.push_back(p[i]);
        else v2.push_back(p[i]);
    }
    for(int i=0; i<v1.size(); i++) {
        if(i==0) re[v1[i].second]=0;
        else re[v1[i].second]=re[v1[i-1].second]+v1[i-1].first;
    }
    for(int i=0; i<v2.size(); i++) {
        if(i==0) re[v2[i].second]=0;
        else re[v2[i].second]=re[v2[i-1].second]+v2[i-1].first;
    }
    for(int i=1; i<=n; i++) cout << re[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    souptl();
}
