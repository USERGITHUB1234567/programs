#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Step 1: Compute the KMP pi array
    vector<int> pi(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int j = pi[i - 1];
        while (j > 0 && a[i] != a[j + 1]) {
            j = pi[j];
        }
        if (a[i] == a[j + 1]) {
            j++;
        }
        pi[i] = j;
    }

    // Step 2: Mark valid distances. 
    // valid[D] = true if there is AT LEAST ONE pair at distance D with different elements.
    vector<bool> valid(n + 1, true);
    valid[0] = false; // Distance 0 is trivial (same element)

    // A distance D is invalid ONLY IF the prefix of length (n-D) equals the suffix of length (n-D).
    // These lengths are exactly the borders found by KMP.
    int L = pi[n];
    while (L > 0) {
        valid[n - L] = false;
        L = pi[L];
    }

    // Step 3: Compute the prefix maximums of valid distances
    vector<int> max_valid(n + 1, -1);
    int current_max = -1;
    for (int d = 1; d <= n; d++) {
        if (valid[d]) {
            current_max = d;
        }
        max_valid[d] = current_max;
    }

    // Step 4: For each k from 2 to n, we want the max valid distance < k (which is <= k - 1)
    for (int k = 2; k <= n; ++k) {
        cout << max_valid[k - 1] << (k == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}