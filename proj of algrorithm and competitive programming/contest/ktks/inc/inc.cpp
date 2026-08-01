#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int m, n;
int a[5005], b[5005];
vector<int> in(vector<int>& a) {
    vector<int> lis;
    for (int i : a) {
        auto it = lower_bound(lis.begin(), lis.end(), i);
        if (it == lis.end())
            lis.push_back(i);
        else
            *it = i;
    }
    return lis;
}
void soup() {
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    unordered_map<int, int> id;
    for (int i = 1; i <= n; i++) id[b[i]] = i;
    vector<int> com;
    for (int i = 1; i <= m; i++) {
        if (id.count(a[i])) {
            com.push_back(id[a[i]]);
        }
    }
    vector<int> lis = in(com);
    cout << lis.size() << "\n";
    if (!lis.empty()) {
        vector<int> kq;
        for (int i : lis) kq.push_back(b[i]);
        for (int i : kq) cout << i << " ";
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //freopen("inc.inp", "r", stdin);
    //freopen("inc.out", "w", stdout);
    soup();
}
