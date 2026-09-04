#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,maxt=1000006;
vector<vector<vector<string>>>test_case;
int tc,n_case[maxt];
namespace appetizersoup{
    vector<int>adj[maxn];
    unordered_map<string,vector<int>>ending;
    int out[maxn],orig_out[maxn];
    short state[maxn];
    void bfs(int n) {
        queue<int>q;
        for(int i=0; i<n; ++i) {
            if(!out[i]) {
                state[i]=-1;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u=q.front();q.pop();
            for(int v:adj[u]) {
                if(!state[v]) {
                    if(state[u]==-1) {state[v]=1;q.push(v);}
                    else if(state[u]==1) {
                        --out[v];
                        if(!out[v]) {
                            state[v]=-1;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    void implement() {
        for(int t=0; t<tc; ++t) {
            int n=n_case[t];
            ending.clear();
            for(int i=0; i<n; ++i) {
                out[i]=0;
                state[i]=0;
                adj[i].clear();
                //ending[i].clear();
            }
            for(int i=0; i<n; ++i) {
                string t1=test_case[t][i][0],t2=test_case[t][i][1];
                ending[t2].push_back(i);
            }
            for(int i=0; i<n; ++i) {
                string t1=test_case[t][i][0],t2=test_case[t][i][1];
                //ending[t2].push_back(i);
                for(int j:ending[t1]) {
                    ++out[j];
                    adj[i].push_back(j);
                }
            }
            for(int i=0; i<n; ++i) orig_out[i]=out[i];
            bfs(n);
            bool win=false,draw=false;
            for(int i=0; i<n; ++i) {
                if(orig_out[i]) {
                    if(state[i]==-1) win=true;
                    else if(!state[i]) draw=true;
                }
            }
            if(win) cout << "Quang";
            else if(draw) cout << "Hoa";
            else cout << "Hieu";
            cout << '\n';
        }
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> tc;
    test_case.reserve(tc);
    for(int i=0; i<tc; ++i) {
        cin >> n_case[i];
        vector<vector<string>>tmp;
        tmp.reserve(n_case[i]);
        for(int j=1; j<=n_case[i]; ++j) {
            string t1,t2;cin >> t1 >> t2;
            vector<string>a={t1,t2};
            tmp.push_back(a);
        }
        test_case.push_back(tmp);
    }
    appetizersoup::implement();
}