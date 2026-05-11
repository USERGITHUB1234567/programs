#include <bits/stdc++.h>
using namespace std;
const int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[30][30];
int n, m, k;
pair<int, int> ans[30];
void dfs(int cnt, int i, int j){
    if (cnt > k){
        for(int p = 1; p <= k; p++)
            cout << char('A' + ans[p].second - 1) << ans[p].first;
        cout<<"\n";
        exit(0);
    }
    if(i < 1 || i>m || j<1 || j>n || visited[i][j]) return;
    ans[cnt] = {i,j};
    visited[i][j] = true;
    for(int p = 0; p<8; p++)
        dfs(cnt + 1, i + di[p], j + dj[p]);
    visited[i][j] = false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(visited, false, sizeof(visited));
    cin >> m >> n;
    k = m * n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dfs(1, i, j);
        }
    }
    cout << "impossible";
    return 0;
}
