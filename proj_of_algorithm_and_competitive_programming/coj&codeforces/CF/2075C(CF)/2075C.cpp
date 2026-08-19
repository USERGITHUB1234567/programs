#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        // Read the capacities for m colors.
        vector<int> a(m);
        for (int i = 0; i < m; i++){
            cin >> a[i];
        }

        // Sort capacities to allow binary search.
        sort(a.begin(), a.end());

        int ans = 0;
        // For each possible split, where i is the number of planks painted with one color.
        for (int i = 1; i < n; i++){
            // Number of colors that can paint at least i planks.
            int leftCount = m - (lower_bound(a.begin(), a.end(), i) - a.begin());
            // Number of colors that can paint at least n-i planks.
            int rightCount = m - (lower_bound(a.begin(), a.end(), n - i) - a.begin());
            // Colors that qualify for both segments (must subtract to avoid using the same color twice).
            int common = m - (lower_bound(a.begin(), a.end(), max(i, n - i)) - a.begin());

            ans += leftCount * rightCount - common;
        }

        cout << ans << "\n";
    }

    return 0;
}
