#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int d = 0;
        int se = 0;
        for (char c : s) {
            if (c == '(') d++;
            else d--;
            if (d == 0) se++;
        }
        cout << (se >= 2 ? "YES" : "NO") << '\n';
    }

    return 0;
}
