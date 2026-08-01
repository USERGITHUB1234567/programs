#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100000;
const int MAXB = 31;              // up to bit 31 for values ≤10^9

int n;
ll a[maxn+5];

struct Trie {
    // We need up to (n * (MAXB+1)) nodes
    int tr[(maxn+5)*(MAXB+1)][2];
    int nodes;

    Trie() {
        nodes = 1;               // root = 1
        memset(tr, 0, sizeof tr);
    }

    // Insert value x into trie
    void add(int x) {
        int p = 1;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!tr[p][bit]) 
                tr[p][bit] = ++nodes;
            p = tr[p][bit];
        }
    }

    // Query maximum x ^ y over all y already inserted
    int query(int x) {
        int p = 1, ans = 0;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (x >> b) & 1;
            // Prefer opposite bit to maximize XOR
            if (tr[p][bit^1]) {
                ans |= (1 << b);
                p = tr[p][bit^1];
            } else {
                p = tr[p][bit];
            }
        }
        return ans;
    }
} trie;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    if (n < 2) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    trie.add((int)a[1]);
    for (int i = 2; i <= n; i++) {
        ans = max(ans, (ll)trie.query((int)a[i]));
        trie.add((int)a[i]);
    }

    cout << ans;
}
