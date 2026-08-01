#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }
    sort(prices.rbegin(), prices.rend());

    int total_cost = 0;
    for (int i = 0; i < N; ++i) {
        if ((i + 1) % 3 == 0) {
            continue;
        }
        total_cost += prices[i];
    }
    cout << total_cost;
    return 0;
}
