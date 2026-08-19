#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int d[5001][5001];
vector<int> adj[5003];
queue<pair<int,int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(d, -1, sizeof(d));

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++){
            if(s[j-1] == '1'){
                if(i != j)
                    adj[i].push_back(j);
            }
        }
    }
    d[1][n] = 0;
    q.push({1, n});
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        if(r == c){
            cout << d[r][c];
            return 0;
        }
        for (int nr : adj[r]){
            for (int nc : adj[c]){
                if(d[nr][nc] == -1){
                    d[nr][nc] = d[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    cout << d[1][n];
    return 0;
}
