#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>>r,u;
namespace souptrau{
    void implement() {
        vector<long long>state(k+1,0);
        vector<bool>mk(n+1,false);
        int cur=0;
        while(true) {
            if(cur>=n) break;
            bool stop=true;
            for(int i=1; i<=n; ++i) {
                if(mk[i]) continue;
                bool ck=true;
                for(int j=1; j<=k; ++j) if(state[j]<r[i][j]) {ck=false;break;}
                if(ck) {
                    stop=false;
                    for(int j=1; j<=k; ++j) state[j]+=u[i][j];
                    ++cur;
                    mk[i]=true;
                }
            }
            if(stop) break;
        }
        cout << cur;
    }
}
namespace soupfull{
    void implement() {
        int ans=0;
        vector<bool>mk(n+1,false);
        vector<long long>state(k+1,0);
        vector<int>cnt(n+1,0),cur(k+1,0);
        vector<pair<int,int>>store[k+1];
        queue<int>q;
        for(int i=1; i<=n; ++i) {
            bool ck=true;
            for(int j=1; j<=k; ++j) {
                if(r[i][j]>0) {ck=false;break;}
            }
            if(ck) {
                mk[i]=true;
                for(int j=1; j<=k; ++j) state[j]+=u[i][j];
                ++ans;

            }
        }
        for(int i=1; i<=n; ++i) {
            if(!mk[i]) {
                for(int j=1; j<=k; ++j) {
                    store[j].push_back({r[i][j],i});
                }
            }
        }
        // for(int i=1; i<=k; ++i) cout << store[i].size() << ' ';
        // cout << '\n';
        for(int i=1; i<=k; ++i) sort(store[i].begin(),store[i].end());
        // for(int i=1; i<=k; ++i) {
        //     for(auto[x,y]:store[i]) cout << x << ' ' << y << '\n';
        //     cout << '\n';
        // }
        // for(int i=1; i<=k; ++i) cout << state[i] << ' ';
        // cout << '\n';
        for(int i=1; i<=k; ++i) {
            int& id=cur[i];
            while(id<store[i].size() && state[i]>=store[i][id].first) {
                //cerr << id << ' ';
                ++cnt[store[i][id].second];
                if(cnt[store[i][id].second]==k) {q.push(store[i][id].second);}
                ++id;
            }
            //cerr << '\n';
        }
        // cout << q.size() << '\n';
        // for(int i=1; i<=n; ++i) cout << cnt[i] << ' ';
        while(!q.empty()) {
            int v=q.front();q.pop();
            ++ans;
            for(int i=1; i<=k; ++i) {state[i]+=u[v][i];}
            for(int i=1; i<=k; ++i) {
                int& id=cur[i];
                while(id<store[i].size() && state[i]>=store[i][id].first) {
                    ++cnt[store[i][id].second];
                    if(cnt[store[i][id].second]==k) {q.push(store[i][id].second);}
                    ++id;
                }
            }
        }
        cout << ans;
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    // freopen("topic.inp", "r", stdin);
    // freopen("topic.out", "w", stdout);
    //cout << 'a';
    cin >> n >> k;
    r.assign(n+1,vector<int>(k+1,0));
    u.assign(n+1,vector<int>(k+1,0));
    for(int i=1; i<=n; ++i) for(int j=1; j<=k; ++j) cin >> r[i][j];
    for(int i=1; i<=n; ++i) for(int j=1; j<=k; ++j) cin >> u[i][j];
    if(n<=100 && k<=100)souptrau::implement();
    //cout << '\n';
    else soupfull::implement();
}
/*
3 3
0 0 0
7 9 2
7 8 9
7 8 2
7 7 7
8 10 9

4 3
5 1 0
0 1 5
0 0 0
7 7 7
0 5 6
1 1 1
8 2 0
8 1 4
*/
