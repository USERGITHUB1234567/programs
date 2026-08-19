#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,c[maxn],q;
vector<int>key[maxn];
pair<int,int>query[maxn];
namespace soup1{
    vector<pair<int,int>>adj[maxn];
    bool bfs(int st, int t) {
        if(st==t) return true;
        int l=st,r=st;
        unordered_map<int,bool>mk;
        for(int i:key[st]) mk[i]=true;
        while(true) {
            bool ck=false;
            while(l>1 && mk[c[l-1]]) {
                --l;
                ck=true;
                for(int i:key[l]) mk[i]=true;
            }
            while(r<n && mk[c[r]]) {
                ++r;
                ck=true;
                for(int i:key[r]) mk[i]=true;
            }
            if(!ck) break;
        }
        return l<=t && r>=t;
    }
    void implement() {
        for(int i=1; i<n; ++i) {
            int j=i+1;
            adj[i].push_back({j,c[i]});
            adj[j].push_back({i,c[i]});
        }
        for(int i=1; i<=q; ++i) {
            auto[x,y]=query[i];
            if(bfs(x,y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
namespace soupfull{
    void implement() {

    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;for(int i=1; i<n; ++i) cin >> c[i];
    for(int i=1; i<=n; ++i) {
        int b;cin >> b;
        for(int j=1; j<=b; ++j) {
            int x;cin >> x;
            key[i].push_back(x);
        }
    }
    cin >> q;
    for(int i=1; i<=q; ++i) cin >> query[i].first >> query[i].second;
    soup1::implement();
    return 0;
}