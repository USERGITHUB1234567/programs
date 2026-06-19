#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 300005;
const int HEAD = MAXN - 1;
const int TAIL = 0;

int prev_node[MAXN];
int next_node[MAXN];
int cnt[MAXN];
int freq_cnt[MAXN];
long long sum_f2 = 0;

inline void init_list() {
    prev_node[TAIL] = HEAD;
    next_node[HEAD] = TAIL;
}

inline void insert_before(int node, int before_this) {
    int prv = prev_node[before_this];
    next_node[prv] = node;
    prev_node[node] = prv;
    next_node[node] = before_this;
    prev_node[before_this] = node;
}

inline void insert_after(int node, int after_this) {
    int nxt = next_node[after_this];
    next_node[after_this] = node;
    prev_node[node] = after_this;
    next_node[node] = nxt;
    prev_node[nxt] = node;
}

inline void remove_node(int node) {
    int prv = prev_node[node];
    int nxt = next_node[node];
    next_node[prv] = nxt;
    prev_node[nxt] = prv;
}

inline void add(int x) {
    int f = cnt[x];
    int nxt_f = f + 1;
    
    if (freq_cnt[nxt_f] == 0) {
        if (f == 0) insert_before(nxt_f, TAIL);
        else insert_before(nxt_f, f);
    }
    freq_cnt[nxt_f]++;
    
    if (f > 0) {
        freq_cnt[f]--;
        if (freq_cnt[f] == 0) remove_node(f);
    }
    
    cnt[x] = nxt_f;
    sum_f2 += 2LL * f + 1;
}

inline void remove_elem(int x) {
    int f = cnt[x];
    int nxt_f = f - 1;
    
    if (nxt_f > 0) {
        if (freq_cnt[nxt_f] == 0) insert_after(nxt_f, f);
        freq_cnt[nxt_f]++;
    }
    
    freq_cnt[f]--;
    if (freq_cnt[f] == 0) remove_node(f);
    
    cnt[x] = nxt_f;
    sum_f2 -= 2LL * f - 1;
}

int BLOCK_SIZE;

struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        int b1 = l / BLOCK_SIZE;
        int b2 = other.l / BLOCK_SIZE;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? r < other.r : r > other.r;
    }
};

pair<long long, long long> active_blocks[1000];
pair<long long, long long> E_blocks[1000];
pair<long long, long long> O_blocks[1000];

long long solve_half(pair<long long, long long>* blocks, int k) {
    long long ans_dist = 0, sum_x = 0, sum_ix = 0, idx = 0, Sum_v2 = 0;

    for (int i = 0; i < k; i++) {
        long long v = blocks[i].first;
        long long c = blocks[i].second;

        long long sum_j = c * idx + c * (c - 1) / 2;
        ans_dist += v * sum_j * sum_x - c * v * sum_ix;

        long long c1 = c, c2 = c - 1, c3 = c + 1;
        if (c1 % 2 == 0) c1 /= 2; else c2 /= 2;
        if (c1 % 3 == 0) c1 /= 3; else if (c2 % 3 == 0) c2 /= 3; else c3 /= 3;
        ans_dist += v * v * c1 * c2 * c3;

        sum_x += c * v;
        sum_ix += v * sum_j;
        idx += c;
        Sum_v2 += c * v * v;
    }

    return ans_dist - (sum_x * sum_x - Sum_v2) / 2;
}

long long part2_block(pair<long long, long long>* active, int active_k) {
    int e_k = 0, o_k = 0;
    long long pos = 0;
    
    for (int i = 0; i < active_k; i++) {
        long long v = active[i].first;
        long long c = active[i].second;
        
        long long c_even = (pos + c + 1) / 2 - (pos + 1) / 2;
        long long c_odd = c - c_even;
        
        if (c_even > 0) E_blocks[e_k++] = {v, c_even};
        if (c_odd > 0) O_blocks[o_k++] = {v, c_odd};
        
        pos += c;
    }
    
    long long ans = solve_half(E_blocks, e_k) + solve_half(O_blocks, o_k);
    
    long long sum_E = 0, sum_iE = 0, idxE = 0;
    for (int i = 0; i < e_k; i++) {
        long long v = E_blocks[i].first;
        long long c = E_blocks[i].second;
        long long sum_i = c * idxE + c * (c - 1) / 2;
        sum_E += c * v;
        sum_iE += v * sum_i;
        idxE += c;
    }
    
    long long sum_O = 0, sum_jO = 0, idxO = 0;
    for (int i = 0; i < o_k; i++) {
        long long v = O_blocks[i].first;
        long long c = O_blocks[i].second;
        long long sum_j = c * idxO + c * (c - 1) / 2;
        sum_O += c * v;
        sum_jO += v * sum_j;
        idxO += c;
    }
    
    ans += sum_iE * sum_O + sum_E * sum_jO;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    BLOCK_SIZE = max(1, (int)(n / sqrt(max(1, q))));
    
    vector<int> a(n);
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vals[i] = a[i];
    }
    
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    }
    
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());
    
    init_list();
    vector<long long> ans(q);
    int current_l = 1, current_r = 0;
    
    for (int i = 0; i < q; i++) {
        int L = queries[i].l;
        int R = queries[i].r;
        
        while (current_l > L) { current_l--; add(a[current_l - 1]); }
        while (current_r < R) { current_r++; add(a[current_r - 1]); }
        while (current_l < L) { remove_elem(a[current_l - 1]); current_l++; }
        while (current_r > R) { remove_elem(a[current_r - 1]); current_r--; }
        
        long long len = R - L + 1;
        long long part1 = len * len + (len - sum_f2) / 2;
        
        int active_k = 0;
        for (int curr = next_node[HEAD]; curr != TAIL; curr = next_node[curr]) {
            active_blocks[active_k++] = {curr, freq_cnt[curr]};
        }
        
        ans[queries[i].id] = part1 + part2_block(active_blocks, active_k);
    }
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}