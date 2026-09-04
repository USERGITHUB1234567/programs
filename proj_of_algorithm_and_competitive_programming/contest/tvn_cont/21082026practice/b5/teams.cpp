#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>>player;
int main(int argc, char** argv) {
    freopen("teams.inp", "r", stdin);
    freopen("teams.out", "w", stdout);
    cin >> n;
    player.reserve(n);
    int sum=0;
    vector<int>p(n),s(n);
    for(int i=0; i<n; ++i) cin >> s[i];for(int i=0; i<n; ++i) cin >> p[i];
    for(int i=0; i<n; ++i) {
        player.push_back({p[i],s[i]});
        sum+=s[i];
    }
    vector<int>f1((sum+1),-1e9),f2(((sum<<1)<<1),-1e9);int cur=0;
    sort(player.begin(),player.end(),[](pair<int,int>a,pair<int,int>b){return a.first>b.first;});
    for(int i=0; i<n; ++i) {
        auto[u,v]=player[i];
        vector<int>nxt1=f1,nxt2=f2;
        nxt1[v]=max(nxt1[v],u);
        for(int j=0; j<=cur; ++j) {
            if(f1[j]!=-1e9)nxt1[j+v]=max(nxt1[j+v],f1[j]);
            if(f1[j]!=-1e9)nxt2[j-v+sum]=max(nxt2[j+sum-v],f1[j]-u);
        }
        for(int j=-cur; j<=cur; ++j) {
            if(f2[j+sum]==-1e9) continue;
            nxt2[j+sum+v]=max(nxt2[j+sum+v],f2[j+sum]);
            nxt2[j+sum-v]=max(nxt2[j+sum-v],f2[j+sum]);
        }
        cur+=v;
        f1=move(nxt1);
        f2=move(nxt2);
    }
    cout << f2[sum];
}
/*
8
4 7 3 8 5 6 9 2
15 3 20 11 8 30 6 25
*/