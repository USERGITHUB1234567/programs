#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
using namespace std; 

const int maxn = 1005; 

int n, m;
vector<int> adj[maxn];

class edmonds_karp {
private:
    int c[maxn][maxn], f[maxn][maxn], trace[maxn], maxflow, s, t, num_nodes;

public:
    edmonds_karp(int _n) : num_nodes(_n) {
        s = 1; t = num_nodes; 
        maxflow = 0;
        memset(c, 0, sizeof(c)); 
        memset(f, 0, sizeof(f));
    }

    inline void change(int u, int v, int k) {
        c[u][v] += k; // Dùng += an toàn hơn
    }

    inline bool check() {
        return trace[t] != 0;
    }

    void bfs() {
        fill(trace + 1, trace + 1 + num_nodes, 0);
        trace[s] = -1;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                // c[u][v] - f[u][v] là sức chứa thặng dư (Residual Capacity)
                if(trace[v] || c[u][v] - f[u][v] <= 0) continue;
                trace[v] = u;
                q.push(v);
            }
        }
    }

    inline void increase() {
        int delta = INT_MAX;
        int v = t;
        while(v != s) {
            int u = trace[v];
            delta = min(delta, c[u][v] - f[u][v]);
            v = u;
        }
        maxflow += delta;
        v = t;
        while(v != s) {
            int u = trace[v];
            f[u][v] += delta;
            f[v][u] -= delta; // Cập nhật cạnh ngược
            v = u;
        }
        // XÓA ĐOẠN LƯU path Ở ĐÂY!
    }

    // Viết lại hàm trích xuất đường đi TỪ MẠNG LUỒNG KẾT QUẢ
    vector<vector<int>> res() {
        vector<vector<int>> ans;
        for(int i = 0; i < maxflow; ++i) {
            vector<int> path;
            int u = s;
            path.push_back(u);
            while(u != t) {
                bool found = false;
                for(int v : adj[u]) {
                    // Chỉ đi theo các cạnh GỐC (c > 0) và CÓ LUỒNG (f > 0)
                    if(c[u][v] > 0 && f[u][v] > 0) {
                        f[u][v]--; // Tiêu thụ luồng để không dùng lại cạnh này
                        u = v;
                        path.push_back(u);
                        found = true;
                        break; // Chỉ cần tìm thấy 1 nhánh đi tiếp là break
                    }
                }
                if (!found) break; // Đề phòng lặp vô tận (nếu có lỗi)
            }
            ans.push_back(path);
        }
        return ans;
    }
};

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); 
    
    if (cin >> n >> m) {
        edmonds_karp ed(n);
        for(int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // Thêm cạnh ngược để tìm đường tăng luồng
            ed.change(u, v, 1);
        }
        
        while(true) {
            ed.bfs();
            if(!ed.check()) break;
            ed.increase();
        }
        
        vector<vector<int>> ans = ed.res();
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i].size() << '\n';
            for(int j : ans[i]) cout << j << ' ';
            cout << '\n';
        }
    }
    return 0; 
}