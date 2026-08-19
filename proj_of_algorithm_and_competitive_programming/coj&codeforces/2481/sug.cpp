/**/ 
//#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout); 
#define all(x) x.begin(), x.end() 
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end()); 
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i)) 
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i)) 
#define eb emplace_back 
#define fi first 
#define se second 
#define pb push_back 
using namespace std; 
using namespace std::chrono; 
static const int maxd=1003; 
typedef short bignum[maxd]; 
typedef long long ll; 
typedef long double ld; 
const int maxn=100005,mod=1000000007,maxb=320; 

// ... (Đoạn namespace utilities và random generator của bạn giữ nguyên) ...

int n,c[maxn];
vector<int>adj[maxn];

// FIX 1: Đổi thành kiểu long long để lưu trữ tổng các màu không bị tràn số
pair<int, long long> save[maxn]; 
unordered_map<int,int>cnt[maxn];

void dfs(int u, int p) {
    cnt[u][c[u]] = 1; // Khởi tạo thay vì ++
    int mx = 1;
    long long tmp = c[u]; // FIX 2: tmp phải là long long 

    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            
            // FIX 3: Nếu hoán đổi Map, phải cập nhật luôn mx và tmp theo Map của đỉnh con
            if(cnt[v].size() > cnt[u].size()) {
                cnt[u].swap(cnt[v]);
                mx = save[v].fi;
                tmp = save[v].se;
            }
            
            for(auto [t, z] : cnt[v]) {
                cnt[u][t] += z;
                int cur = cnt[u][t];
                if(cur > mx) {
                    mx = cur;
                    tmp = t;
                } else if(cur == mx) {
                    tmp += t;
                }
            }
            cnt[v].clear();
        }
    }
    save[u] = {mx, tmp};
}

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) cout << save[i].se << (i < n ? " " : "");
    return 0; 
}