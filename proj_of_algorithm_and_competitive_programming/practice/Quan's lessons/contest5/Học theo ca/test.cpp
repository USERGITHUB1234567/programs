/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 

using namespace std; 

// Sửa giới hạn mảng lên 500005 theo Subtask 2
const int maxn = 500005; 
int n, m, q;
pair<int,int> conf[maxn], query[maxn];
vector<int> bucket[maxn]; // Bỏ ra ngoài để tránh Memory Limit do cấp phát lại vector liên tục

class disjoint_set_union{
    private:
        vector<int> p;
    public:
        disjoint_set_union(int _n) {
            p.resize(_n);
            for(int i=0; i<_n; ++i) p[i]=i;
        }
        inline int root(int u) { return (p[u]==u ? u : p[u]=root(p[u])); }
        inline void unite(int v, int u) {
            u = root(u), v = root(v);
            if(u!=v) p[v] = u;
        }
        inline bool same(int u, int v) { return root(u) == root(v); }
};

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    if (!(cin >> n >> m >> q)) return 0;
    
    for(int i=1; i<=m; ++i) cin >> conf[i].first >> conf[i].second;
    for(int i=1; i<=q; ++i) cin >> query[i].first >> query[i].second;
    
    vector<int> l(q+1, 0), r(q+1, m);
    int st = 0;
    
    // 1. Tìm thời điểm lớn nhất st gây ra chu trình lẻ của cấu hình gốc
    {
        disjoint_set_union dsu(2 * n + 5);
        for(int i=m; i>=1; --i) {
            auto[u,v] = conf[i];
            if(dsu.same(u, v)) {
                st = i; 
                break;
            }
            // Gộp đỉnh để kiểm tra đồ thị 2 phía
            dsu.unite(u, v + n);
            dsu.unite(v, u + n);
        }
    }
    
    // Khởi tạo giới hạn dưới cho mọi truy vấn luôn >= st
    for(int i=1; i<=q; ++i) l[i] = st;
    
    // 2. Parallel Binary Search
    while(true) {
        int stop = true;
        for(int i=1; i<=q; ++i) {
            if(l[i] < r[i]) {
                stop = false;
                int mid = (l[i] + r[i]) >> 1;
                bucket[mid].push_back(i);
            }
        }
        if(stop) break;
        
        disjoint_set_union dsu(2 * n + 5);
        for(int i=m; i>=st; --i) {
            // Xử lý các câu truy vấn có mid == i
            // LƯU Ý: Tại thời điểm này, DSU đang chứa toàn bộ các cạnh STRICTLY > i
            for(int j : bucket[i]) {
                auto[a, b] = query[j];
                
                // Nếu cùng tập thì việc gắn thêm (a, b) sẽ sinh ra chu trình lẻ (chứ không phải 2 phía)
                // Suy ra i là quá bé, ta cần số ngày > i
                if(dsu.same(a, b)) l[j] = i + 1; 
                else r[j] = i; // Sửa lỗi r[i]=i
            }
            bucket[i].clear(); // Dọn dẹp để tái sử dụng cho lượt Loop kế tiếp
            
            // Add cạnh i vào đồ thị để phục vụ cho các lượt i-1 tiếp theo
            if (i > 0) {
                auto[u,v] = conf[i];
                dsu.unite(u, v + n);
                dsu.unite(v, u + n);
            }
        }
    }
    
    for(int i=1; i<=q; ++i) cout << l[i] << '\n';
    return 0; 
} 
/**/