#include <bits/stdc++.h>
using namespace std;
const int maxn=1003;
int n,mk[maxn];
bool a[maxn][maxn];
vector<int>adj[maxn];
int main(int argc, char** argv) {
    cin >> n;
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=n; ++j) {
            cin >> a[i][j];
            if(a[i][j]) adj[i].push_back(j);
        }
    array<int,3>res={-1,-1,-1};
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) mk[j]=0;
        vector<int>store,v;
        for(int j:adj[i]) {mk[j]=-1;store.push_back(j);}
        for(int j:store) {
            for(int k:adj[j]) mk[k]=j;
        }
        for(int j=1; j<=n; ++j) if(mk[j]!=-1 && mk[j] && a[j][i]==true) {res={i,mk[j],j};break;}
    }
    cout << res[0] << ' ' << res[1] << ' ' << res[2];
}
/*
5
0 1 1 1 1
0 0 0 1 1
0 1 0 0 0
0 0 1 0 1
0 0 1 0 0
*/
