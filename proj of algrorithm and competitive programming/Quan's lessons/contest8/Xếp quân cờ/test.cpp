#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc Disjoint Set Union (DSU) để quản lý tập hợp
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

struct Edge {
    int u, v;
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsuX(n), dsuY(n);
    vector<Edge> x_edges, y_edges;

    // Đọc các chỉ dẫn và phân loại thành cạnh Đồ thị / cạnh DSU
    for (int i = 0; i < m; i++) {
        int u, v;
        char type;
        cin >> u >> type >> v;
        
        if (type == 'l') {          // u trái v
            dsuY.unite(u, v);       // y_u = y_v
            x_edges.push_back({u, v}); // x_u < x_v
        } else if (type == 'r') {   // u phải v
            dsuY.unite(u, v);       // y_u = y_v
            x_edges.push_back({v, u}); // x_v < x_u
        } else if (type == 'd') {   // u dưới v
            dsuX.unite(u, v);       // x_u = x_v
            y_edges.push_back({u, v}); // y_u < y_v
        } else if (type == 'u') {   // u trên v
            dsuX.unite(u, v);       // x_u = x_v
            y_edges.push_back({v, u}); // y_v < y_u
        }
    }

    // Xây dựng đồ thị bất đẳng thức cho X
    vector<vector<int>> adjX(n + 1);
    vector<int> inDegreeX(n + 1, 0);
    for (auto edge : x_edges) {
        int rootU = dsuX.find(edge.u);
        int rootV = dsuX.find(edge.v);
        // Bắt lỗi: Nếu tồn tại x_u < x_v nhưng u và v lại thuộc cùng nhóm x_u = x_v
        if (rootU == rootV) {
            cout << "NO\n";
            return;
        }
        adjX[rootU].push_back(rootV);
        inDegreeX[rootV]++;
    }

    // Xây dựng đồ thị bất đẳng thức cho Y
    vector<vector<int>> adjY(n + 1);
    vector<int> inDegreeY(n + 1, 0);
    for (auto edge : y_edges) {
        int rootU = dsuY.find(edge.u);
        int rootV = dsuY.find(edge.v);
        if (rootU == rootV) {
            cout << "NO\n";
            return;
        }
        adjY[rootU].push_back(rootV);
        inDegreeY[rootV]++;
    }

    // Sắp xếp Topo và gán tọa độ cho đồ thị X
    queue<int> qX;
    vector<int> valX(n + 1, 1); // Khởi tạo tọa độ nhỏ nhất là 1
    int countX = 0, rootsX = 0;
    
    for (int i = 1; i <= n; i++) {
        if (dsuX.find(i) == i) {
            rootsX++;
            if (inDegreeX[i] == 0) qX.push(i);
        }
    }
    
    while (!qX.empty()) {
        int u = qX.front();
        qX.pop();
        countX++;
        for (int v : adjX[u]) {
            valX[v] = max(valX[v], valX[u] + 1); // Cập nhật tọa độ đảm bảo lớn hơn node trước nó
            inDegreeX[v]--;
            if (inDegreeX[v] == 0) qX.push(v);
        }
    }
    
    if (countX != rootsX) { // Tồn tại chu trình
        cout << "NO\n";
        return;
    }

    // Sắp xếp Topo và gán tọa độ cho đồ thị Y
    queue<int> qY;
    vector<int> valY(n + 1, 1);
    int countY = 0, rootsY = 0;
    
    for (int i = 1; i <= n; i++) {
        if (dsuY.find(i) == i) {
            rootsY++;
            if (inDegreeY[i] == 0) qY.push(i);
        }
    }
    
    while (!qY.empty()) {
        int u = qY.front();
        qY.pop();
        countY++;
        for (int v : adjY[u]) {
            valY[v] = max(valY[v], valY[u] + 1);
            inDegreeY[v]--;
            if (inDegreeY[v] == 0) qY.push(v);
        }
    }
    
    if (countY != rootsY) { // Tồn tại chu trình
        cout << "NO\n";
        return;
    }

    // Đã thỏa mãn mọi điều kiện, in kết quả
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << valX[dsuX.find(i)] << " " << valY[dsuY.find(i)] << "\n";
    }
}

int main() {
    // Tối ưu hóa I/O để chống TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}