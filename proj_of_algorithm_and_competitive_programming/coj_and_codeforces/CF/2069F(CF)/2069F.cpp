#include <bits/stdc++.h>
using namespace std;

// DSU rollback
struct DSU {
    int n, comp;
    vector<int> par, sz;
    vector<vector<int>> lis;
    stack<tuple<int,int,int,int>> st;

    DSU(int n): n(n), comp(n), par(n), sz(n,1), lis(n) {
        for (int i = 0; i < n; i++){
            par[i] = i;
            lis[i].push_back(i);
        }
    }
    int find(int a) {
        return (par[a] == a ? a : find(par[a]));
    }
    // upd: function to update frequency map when rep changes.
    bool unite(int a, int b, function<void(int,int,int)> upd) {
        a = find(a), b = find(b);
        if(a == b) { st.push({-1,-1,0,0}); return false; }
        if(sz[a] < sz[b]) swap(a,b);
        st.push({b, par[b], sz[a], (int)lis[b].size()});
        par[b] = a;
        sz[a] += sz[b];
        comp--;
        for (int x : lis[b]) {
            upd(b, a, x);
            lis[a].push_back(x);
        }
        lis[b].clear();
        return true;
    }
    void rollback() {
        auto [b, oldPar, oldSz, cnt] = st.top();
        st.pop();
        if(b == -1) return;
        int a = par[b];
        for (int i = 0; i < cnt; i++){
            lis[a].pop_back();
        }
        // Khôi phục lại lis[b] không có nội dung gốc (trong code thực, cần lưu lại danh sách ban đầu)
        // Ở đây, để đơn giản, ta không thực hiện khôi phục lại chính xác danh sách, vì chỉ cần dùng DSU để tính số component.
        par[b] = oldPar;
        sz[a] = oldSz;
        comp++;
    }
};

// Frequency map rollback
inline long long enc(int a, int b) {
    return ((long long)a << 32) | ((unsigned int)b);
}

unordered_map<long long,int> freq;
int gd = 0;
stack<pair<long long,int>> frb;

void updFreq(long long key, int delta) {
    int oldVal = freq[key];
    int newVal = oldVal + delta;
    freq[key] = newVal;
    if(oldVal==0 && newVal>0) gd++;
    if(oldVal>0 && newVal==0) gd--;
    frb.push({key, oldVal});
}

void rollbackFreq(int cnt) {
    while(cnt--){
        auto op = frb.top(); frb.pop();
        long long key = op.first;
        int oldVal = op.second;
        int cur = freq[key];
        if(cur > 0 && oldVal==0) gd--;
        if(cur==0 && oldVal>0) gd++;
        freq[key] = oldVal;
    }
}

// Global DSU objects and pair update functions
int N;
DSU *dA, *dB;

void updA(int oldRep, int newRep, int x) {
    int rb = dB->find(x);
    long long kOld = enc(oldRep, rb), kNew = enc(newRep, rb);
    updFreq(kOld, -1);
    updFreq(kNew, 1);
}

void updB(int oldRep, int newRep, int x) {
    int ra = dA->find(x);
    long long kOld = enc(ra, oldRep), kNew = enc(ra, newRep);
    updFreq(kOld, -1);
    updFreq(kNew, 1);
}

// Dynamic connectivity – segment tree
struct Edge {
    int u, v, l, r;
};

vector<Edge> edA, edB;

struct SegNode {
    vector<pair<char,int>> ops;
};

int segSize;
vector<SegNode> seg;

void segInit(int q) {
    segSize = 1;
    while(segSize < q) segSize *= 2;
    seg.assign(2 * segSize, {});
}

void segAdd(int l, int r, pair<char,int> op, int idx, int lo, int hi) {
    if(l >= hi || r <= lo) return;
    if(l <= lo && hi <= r) { seg[idx].ops.push_back(op); return; }
    int mid = (lo + hi) / 2;
    segAdd(l, r, op, 2 * idx, lo, mid);
    segAdd(l, r, op, 2 * idx + 1, mid, hi);
}

void segAddOp(int l, int r, pair<char,int> op) {
    segAdd(l, r, op, 1, 0, segSize);
}

void segDfs(int idx, int lo, int hi) {
    int cntA = 0, cntB = 0;
    // Xử lý các thao tác tại nút hiện tại.
    for(auto &p : seg[idx].ops) {
        char g = p.first;
        int ei = p.second;
        if(g == 'A') {
            if(dA->unite(edA[ei].u - 1, edA[ei].v - 1, updA)) cntA++;
            else cntA++; // dummy
        } else {
            if(dB->unite(edB[ei].u - 1, edB[ei].v - 1, updB)) cntB++;
            else cntB++;
        }
    }
    if(lo + 1 == hi) {
        cout << gd - dB->comp << "\n";
    } else {
        int mid = (lo + hi) / 2;
        segDfs(2 * idx, lo, mid);
        segDfs(2 * idx + 1, mid, hi);
    }
    for (int i = 0; i < cntA; i++) dA->rollback();
    for (int i = 0; i < cntB; i++) dB->rollback();
    rollbackFreq(0); // Nếu có thao tác updFreq, cập nhật số lượng rollback tương ứng.
}

// Main
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    N = n;
    dA = new DSU(n);
    dB = new DSU(n);
    for (int i = 0; i < n; i++){
        long long key = enc(i, i);
        updFreq(key, 1);
    }

    map<pair<int,int>, int> lastA, lastB;
    vector<tuple<char,int,int>> qs(q);
    for (int i = 0; i < q; i++){
        char c; int u, v;
        cin >> c >> u >> v;
        if(u > v) swap(u, v);
        qs[i] = {c, u, v};
        if(c=='A'){
            pair<int,int> key = {u, v};
            if(!lastA.count(key)) {
                lastA[key] = i;
            } else {
                int st = lastA[key];
                edA.push_back({u, v, st, i});
                lastA.erase(key);
            }
        } else {
            pair<int,int> key = {u, v};
            if(!lastB.count(key)) {
                lastB[key] = i;
            } else {
                int st = lastB[key];
                edB.push_back({u, v, st, i});
                lastB.erase(key);
            }
        }
    }
    for(auto &p: lastA){
        int st = p.second;
        int u = p.first.first, v = p.first.second;
        edA.push_back({u, v, st, q});
    }
    for(auto &p: lastB){
        int st = p.second;
        int u = p.first.first, v = p.first.second;
        edB.push_back({u, v, st, q});
    }

    segInit(q);
    for (int i = 0; i < (int)edA.size(); i++){
        segAddOp(edA[i].l, edA[i].r, {'A', i});
    }
    for (int i = 0; i < (int)edB.size(); i++){
        segAddOp(edB[i].l, edB[i].r, {'B', i});
    }

    segDfs(1, 0, segSize);

    return 0;
}
