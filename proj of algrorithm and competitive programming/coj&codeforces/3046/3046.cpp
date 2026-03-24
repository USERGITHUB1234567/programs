#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    if (a[1] == 0) {
        cout << "NO" << endl;
        return 0;
    }

    if (a[s] == 1) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = s + 1; i <= n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            if (b[s] == 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
