#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 300005;

int n, m, k;
int a[MAXN];
int bs;
ll cur = 0;
vector<int> pre;
struct Query {
    int l, r, id;
};
vector<Query> queries;
vector<ll> ans;
unordered_map<int,int> cnt;

inline bool mo_cmp(const Query &A, const Query &B) {
    int ablock = A.l / bs;
    int bblock = B.l / bs;
    if (ablock != bblock) return ablock < bblock;
    return (ablock & 1) ? (A.r > B.r) : (A.r < B.r);
}

void add_index(int idx) {
    // idx is index into pre (0..n)
    int val = pre[idx];
    int need = k ^ val;
    auto it = cnt.find(need);
    if (it != cnt.end()) cur += it->second;
    ++cnt[val];
}
void remove_index(int idx) {
    int val = pre[idx];
    --cnt[val];
    int need = k ^ val;
    auto it = cnt.find(need);
    if (it != cnt.end()) cur -= it->second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m >> k)) return 0;
    pre.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }

    queries.reserve(m);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        // convert to prefix indices: we want pairs (i,j) with l-1 <= i < j <= r
        queries.push_back({l-1, r, i});
    }

    bs = max(1, (int)sqrt(n + 1));
    sort(queries.begin(), queries.end(), mo_cmp);

    ans.assign(m+1, 0);
    // initialize window to [0,0] containing pre[0]
    int L = 0, R = 0;
    cnt.clear();
    cnt[pre[0]] = 1;
    cur = 0;

    for (auto &q : queries) {
        int l = q.l;
        int r = q.r;
        // expand / shrink to [l, r]
        while (L > l) add_index(--L);
        while (R < r) add_index(++R);
        while (L < l) remove_index(L++);
        while (R > r) remove_index(R--);
        ans[q.id] = cur;
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
