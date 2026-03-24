#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int MAXN = 100001;
const int ALPHABET_SIZE = 26;

int to[MAXN][ALPHABET_SIZE], cnt[MAXN];
int sz = 1;

void init_trie() {
    memset(to, 0, sizeof(to));
    memset(cnt, 0, sizeof(cnt));
}

void add(string s) {
    int u = 0;
    for (char c : s) {
        int j = c - 'a';
        if (to[u][j] == 0) to[u][j] = sz++;
        u = to[u][j];
        cnt[u]++;
    }
}

int cntp(string s) {
    int u = 0;
    for (char c : s) {
        u = to[u][c - 'a'];
        if (u == 0) return 0;
    }
    return cnt[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    init_trie();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add(s);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        cout << cntp(s) << "\n";
    }

    return 0;
}
