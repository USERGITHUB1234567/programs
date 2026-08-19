#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int g, n, d = 0;
    cin >> g >> n;
    string w, s;
    cin >> w >> s;
    vector<int> dW(256, 0), ds(256, 0);
    for (char ch : w) dW[ch]++;
    for (int i = 0; i < g; i++) ds[s[i]]++;
    if (dW == ds) d++;

    for (int i = g; i < n; i++) {
        ds[s[i]]++;
        ds[s[i - g]]--;
        if (dW == ds) d++;
    }
    cout << d;
    return 0;
}
