#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<long long> a(n); // Use a vector instead of a fixed array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<long long>()); // Sort in descending order
        long long kq = 0, team_size = 0;

        for (int i = 0; i < n; i++) {
            team_size++;
            if (a[i] * team_size >= x) {
                kq++; // Form a valid team
                team_size = 0; // Reset team size for the next potential team
            }
        }

        cout << kq << "\n"; // Output the number of valid teams
    }

    return 0;
}
