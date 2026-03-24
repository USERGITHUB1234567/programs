#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // If n is even and greater than 1, there is no valid permutation.
        if (n > 1 && n % 2 == 0) {
            cout << "-1\n";
        } else {
            // Generate the valid permutation for odd n or n = 1
            vector<int> perm(n);
            for (int i = 0; i < n; ++i) {
                perm[i] = (i + 2) % n + 1; // Circular shift logic
            }
            for (int i = 0; i < n; ++i) {
                cout << perm[i] << (i == n - 1 ? "\n" : " ");
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
