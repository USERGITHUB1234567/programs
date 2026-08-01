#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1'000'000'007;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, ll val){
        for(; idx<=n; idx += idx&-idx) bit[idx] += val;
    }
    ll sum(int idx){
        ll r=0;
        for(; idx>0; idx -= idx&-idx) r += bit[idx];
        return r;
    }
    ll range_sum(int l, int r){
        if(r<l) return 0;
        return sum(r) - sum(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int task;
    string S;
    if(!(cin >> task)) return 0;
    cin >> S;
    int n = (int)S.size();
    if(n < 4){
        if(task == 1) cout << "NO\n";
        else cout << 0 << '\n';
        return 0;
    }

    int m = n - 3; // number of starting positions for length-4 patterns
    vector<int> val(m+1, 0); // 1..m
    for(int i=1;i<=m;i++){
        // substring starting at i-1 in 0-based
        string t = S.substr(i-1, 4);
        if(t == "2026") val[i] = 1;
        else if(t == "2025") val[i] = -1;
    }

    // prefix sums P[0..m]
    vector<int> P(m+1, 0);
    for(int i=1;i<=m;i++) P[i] = P[i-1] + val[i];

    if(task == 1){
        cout << (P[m] > 0 ? "YES\n" : "NO\n");
        return 0;
    }

    // task == 2: count pairs (i<j) with P[i] < P[j]
    // coordinate compress P values
    vector<int> comp = P;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    auto idx = [&](int x){
        return int(lower_bound(comp.begin(), comp.end(), x) - comp.begin()) + 1; // 1-based
    };

    Fenwick bit((int)comp.size());
    ll ans = 0;
    for(int j=0;j<=m;j++){
        int id = idx(P[j]);
        // number of previous i with P[i] < P[j] is sum over indices < id
        if(id > 1){
            ans += bit.sum(id-1);
            if(ans >= (1LL<<62)) ans %= MOD; // keep it bounded
        }
        // mark current P[j]
        bit.add(id, 1);
    }

    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
