#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; ++i) {
        int A = i;
        int B = f[A];
        int C = f[B];
        if (f[C] == A) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
