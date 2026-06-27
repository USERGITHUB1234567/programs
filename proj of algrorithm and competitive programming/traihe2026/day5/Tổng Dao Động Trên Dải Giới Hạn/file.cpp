#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
using namespace std; 

const int MOD = 1000000007; 
const int MAXN = 200005; 

long long a[MAXN]; 
long long S0[MAXN], S1[MAXN], S2[MAXN]; 

// Fast modular exponentiation
long long power(long long base, long long exp) { 
    long long res = 1; 
    base %= MOD; 
    while (exp > 0) { 
        if (exp % 2 == 1) res = (res * base) % MOD; 
        base = (base * base) % MOD; 
        exp /= 2; 
    } 
    return res; 
} 

long long get_s0(int l, int r) { 
    long long ans = S0[r] - (l > 0 ? S0[l - 1] : 0); 
    return ans < 0 ? ans + MOD : ans; 
} 

long long get_s1(int l, int r) { 
    long long ans = S1[r] - (l > 0 ? S1[l - 1] : 0); 
    return ans < 0 ? ans + MOD : ans; 
} 

long long get_s2(int l, int r) { 
    long long ans = S2[r] - (l > 0 ? S2[l - 1] : 0); 
    return ans < 0 ? ans + MOD : ans; 
} 

struct Node { 
    long long prod; 
    long long sum0; 
    long long sum1; 
    long long sum2; 
    long long lazy; 
} st[MAXN * 4]; 

void apply(int id, int l, int r, long long val) { 
    st[id].lazy = val; 
    long long v_mod = val % MOD; 
    st[id].sum0 = v_mod * get_s0(l, r) % MOD; 
    st[id].sum1 = v_mod * get_s1(l, r) % MOD; 
    st[id].sum2 = v_mod * get_s2(l, r) % MOD; 
    st[id].prod = power((v_mod + 1) % MOD, r - l + 1); 
} 

void push(int id, int l, int r) { 
    if (st[id].lazy != -1) { 
        int mid = l + (r - l) / 2; 
        apply(2 * id, l, mid, st[id].lazy); 
        apply(2 * id + 1, mid + 1, r, st[id].lazy); 
        st[id].lazy = -1; 
    } 
} 

Node merge_nodes(const Node& a, const Node& b) { 
    Node res; 
    res.prod = a.prod * b.prod % MOD; 
    res.sum0 = a.sum0 + b.sum0; 
    if (res.sum0 >= MOD) res.sum0 -= MOD; 
    res.sum1 = a.sum1 + b.sum1; 
    if (res.sum1 >= MOD) res.sum1 -= MOD; 
    res.sum2 = a.sum2 + b.sum2; 
    if (res.sum2 >= MOD) res.sum2 -= MOD; 
    res.lazy = -1; 
    return res; 
} 

void build(int id, int l, int r) { 
    st[id].lazy = -1; 
    if (l == r) { 
        long long v_mod = a[l] % MOD; 
        st[id].sum0 = v_mod; 
        st[id].sum1 = v_mod * l % MOD; 
        st[id].sum2 = v_mod * l % MOD * l % MOD; 
        st[id].prod = (v_mod + 1) % MOD; 
        return; 
    } 
    int mid = l + (r - l) / 2; 
    build(2 * id, l, mid); 
    build(2 * id + 1, mid + 1, r); 
    st[id] = merge_nodes(st[2 * id], st[2 * id + 1]); 
} 

void update(int id, int l, int r, int u, int v, long long val) { 
    if (u <= l && r <= v) { 
        apply(id, l, r, val); 
        return; 
    } 
    push(id, l, r); 
    int mid = l + (r - l) / 2; 
    if (u <= mid) update(2 * id, l, mid, u, v, val); 
    if (v > mid) update(2 * id + 1, mid + 1, r, u, v, val); 
    st[id] = merge_nodes(st[2 * id], st[2 * id + 1]); 
} 

Node query(int id, int l, int r, int u, int v) { 
    if (u <= l && r <= v) return st[id]; 
    push(id, l, r); 
    int mid = l + (r - l) / 2; 
    if (v <= mid) return query(2 * id, l, mid, u, v); 
    if (u > mid) return query(2 * id + 1, mid + 1, r, u, v); 
    return merge_nodes(query(2 * id, l, mid, u, v), query(2 * id + 1, mid + 1, r, u, v)); 
} 

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, q; 
    if (!(cin >> n >> q)) return 0; 
    
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    
    // Precompute Prefix Polynomial Sums
    S0[0] = 1; 
    S1[0] = 0; 
    S2[0] = 0; 
    for (int i = 1; i < n; ++i) { 
        S0[i] = (S0[i - 1] + 1) % MOD; 
        S1[i] = (S1[i - 1] + i) % MOD; 
        S2[i] = (S2[i - 1] + 1LL * i * i % MOD) % MOD; 
    } 
    
    build(1, 0, n - 1); 
    
    while (q--) { 
        int type; 
        cin >> type; 
        if (type == 1) { 
            int l, r; 
            long long v; 
            cin >> l >> r >> v; 
            update(1, 0, n - 1, l, r, v); 
        } else { 
            int l, r; 
            cin >> l >> r; 
            Node res = query(1, 0, n - 1, l, r); 
            
            // Reconstruct Evaluation: -g^2 + (r+l)g - (r+1)(l-1)
            long long term1 = (MOD - res.sum2) % MOD; 
            long long rl = (r + l) % MOD; 
            long long term2 = rl * res.sum1 % MOD; 
            long long const_term = (1LL * (r + 1) % MOD) * ((l - 1 + MOD) % MOD) % MOD; 
            long long term3 = (MOD - const_term) % MOD * res.sum0 % MOD; 
            
            long long total_sum = (term1 + term2 + term3) % MOD; 
            long long ans = total_sum * res.prod % MOD; 
            
            // Multiply by Modular Inverse of 2
            ans = ans * 500000004 % MOD; 
            cout << ans << "\n"; 
        } 
    } 
    return 0; 
}