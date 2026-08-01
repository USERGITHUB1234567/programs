/**/ 
#pragma GCC optimize("O3") 
#include <bits/stdc++.h> 
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i)) 
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i)) 
#define all(x) x.begin(), x.end() 
#define fi first 
#define se second 
using namespace std; 

typedef long long ll; 
const int maxq = 10005; // Q=5000, mỗi Q có 2 chỉ số -> 10000

struct Query {
    int u, v, p;
};

int parent[maxq], dist[maxq];

// DSU với trọng số (Parity)
int find_set(int v) {
    if (v == parent[v]) return v;
    int root = find_set(parent[v]);
    dist[v] ^= dist[parent[v]]; // Cập nhật quan hệ so với root
    return parent[v] = root;
}

bool unite(int u, int v, int p) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    
    if (root_u != root_v) {
        parent[root_u] = root_v;
        // dist[u] ^ dist[root_u] ^ dist[v] = p
        dist[root_u] = dist[u] ^ dist[v] ^ p;
        return true;
    } else {
        // Nếu đã cùng root, kiểm tra mâu thuẫn
        return (dist[u] ^ dist[v]) == p;
    }
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    
    ll n; 
    int q;
    if (!(cin >> n >> q)) return 0;
    
    vector<pair<pair<int, int>, string>> raw_queries(q);
    vector<int> coords;
    
    forw(i, 0, q - 1) {
        cin >> raw_queries[i].fi.fi >> raw_queries[i].fi.se >> raw_queries[i].se;
        // Chúng ta cần S[R] và S[L-1]
        coords.push_back(raw_queries[i].fi.fi - 1);
        coords.push_back(raw_queries[i].fi.se);
    }
    
    // Nén tọa độ
    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end());
    
    auto get_coord = [&](int x) {
        return lower_bound(all(coords), x) - coords.begin();
    };
    
    // Khởi tạo DSU
    forw(i, 0, maxq - 1) {
        parent[i] = i;
        dist[i] = 0;
    }
    
    int ans = q;
    forw(i, 0, q - 1) {
        int u = get_coord(raw_queries[i].fi.fi - 1);
        int v = get_coord(raw_queries[i].fi.se);
        int parity = (raw_queries[i].se == "odd" ? 1 : 0);
        cerr << i << ' ' << u << ' ' << v << '\n';
        if (!unite(u, v, parity)) {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0; 
} 
/**/