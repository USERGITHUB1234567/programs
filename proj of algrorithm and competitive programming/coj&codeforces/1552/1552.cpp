#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100005;
int n;
vector<pair<int,int>> adj[NMAX];
vector<int> ans;

// Hàm dfs trả về true nếu trong cây con của u đã có ứng cử viên được chọn để che phủ
// cạnh từ cha đến u (nếu cạnh đó cần sửa, tức edgeType==2)
bool dfs(int u, int parent, int edgeType) {
    bool covered = false; // có ứng cử viên ở cây con của u hay không
    for(auto &p : adj[u]) {
        int v = p.first, t = p.second;
        if(v == parent) continue;
        // t là loại của cạnh u-v, truyền cho đỉnh con v
        bool childCover = dfs(v, u, t);
        if(childCover)
            covered = true;
    }
    // Nếu cạnh từ parent đến u cần sửa (t==2) mà không có ứng cử viên nào ở cây con che phủ,
    // ta chọn u làm ứng cử viên để sửa tất cả các con đường từ u về 1 (bao gồm cả cạnh này)
    if(edgeType == 2 && !covered) {
        ans.push_back(u);
        return true;
    }
    return covered;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n-1; i++){
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }

    // Gọi DFS từ đỉnh 1, với giá trị edgeType = 0 (không cần sửa) vì 1 là gốc (trụ sở Quốc hội)
    dfs(1, -1, 0);

    cout << ans.size() << "\n";
    // In ra các ứng cử viên được chọn (thứ tự không quan trọng)
    for(auto a : ans) {
        cout << a << " ";
    }

    return 0;
}
