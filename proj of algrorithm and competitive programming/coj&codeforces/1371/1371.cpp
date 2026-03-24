#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> balance(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        balance[ai] -= ci;
        balance[bi] += ci;
    }

    long long totalDebt = 0;
    for (int i = 1; i <= n; ++i) {
        if (balance[i] > 0) {
            totalDebt += balance[i];
        }
    }

    cout << totalDebt << endl;

    return 0;
}
