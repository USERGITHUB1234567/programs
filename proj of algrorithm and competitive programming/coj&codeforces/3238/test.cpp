#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n=0): n(n), bit(n+2,0) {}
    void reset() { fill(bit.begin(), bit.end(), 0); }
    void add(int idx, ll val) {
        for(; idx <= n+1; idx += idx & -idx) bit[idx] += val;
    }
    // range add [l..r] by val
    void range_add(int l, int r, ll val) {
        if(l>r) return;
        add(l, val);
        add(r+1, -val);
    }
    // point query at idx
    ll point(int idx) {
        ll s = 0;
        for(; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if(!(cin >> N >> M)) return 0;
    vector<int> owner(M+1);
    for(int i=1;i<=M;i++) cin >> owner[i];
    vector<ll> need(N+1);
    for(int i=1;i<=N;i++) cin >> need[i];
    int Q; cin >> Q;
    struct Op { int l,r; ll x; };
    vector<Op> ops(Q+1);
    for(int i=1;i<=Q;i++){
        int l,r; ll x; cin >> l >> r >> x;
        ops[i] = {l,r,x};
    }

    // positions of each country
    vector<vector<int>> pos(N+1);
    for(int i=1;i<=M;i++) pos[owner[i]].push_back(i);

    // answers via parallel binary search
    vector<int> L(N+1,1), R(N+1,Q+1);
    // if need==0 then answer 0 (before any event)
    for(int i=1;i<=N;i++){
        if(need[i] <= 0) { L[i] = 0; R[i] = 0; }
    }

    Fenwick bit(M+2);

    bool changed = true;
    while(true){
        // group countries by mid
        vector<vector<int>> byMid(Q+2);
        bool any = false;
        for(int i=1;i<=N;i++){
            if(L[i] < R[i]){
                int mid = (L[i] + R[i]) >> 1;
                byMid[mid].push_back(i);
                any = true;
            }
        }
        if(!any) break;

        bit.reset();
        // apply ops incrementally: we will sweep t from 1..Q and when at t answer group byMid[t]
        for(int t=1;t<=Q;t++){
            // apply op t
            int l = ops[t].l, r = ops[t].r; ll x = ops[t].x;
            if(l <= r){
                bit.range_add(l, r, x);
            } else {
                // wrap: l..M and 1..r
                bit.range_add(l, M, x);
                bit.range_add(1, r, x);
            }
            // process countries that ask mid == t
            if(!byMid[t].empty()){
                for(int country : byMid[t]){
                    // compute total for this country
                    ll total = 0;
                    for(int p : pos[country]){
                        total += bit.point(p);
                        if(total >= need[country]) break; // early stop
                    }
                    if(total >= need[country]){
                        R[country] = t;
                    } else {
                        L[country] = t+1;
                    }
                }
            }
        }
        // Note: countries with mid > Q are handled by L/R logic; loop repeats until convergence
    }

    // output
    for(int i=1;i<=N;i++){
        if(L[i] == 0) cout << 0 << '\n';
        else if(L[i] == Q+1) cout << "NO\n";
        else cout << L[i] << '\n';
    }
    return 0;
}
